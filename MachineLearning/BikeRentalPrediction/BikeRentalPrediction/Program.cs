using System;
using Microsoft.ML;
using Microsoft.ML.Data;
using Microsoft.ML.Trainers;
using Microsoft.ML.Trainers.FastTree;
using Microsoft.ML.Trainers.LightGbm;

namespace BikeSharingPrediction
{
    class Program
    {
        private static string _dataPath = "D:\\Git\\studiesITMO\\MachineLearning\\BikeRentalPrediction\\BikeRentalPrediction\\bike_sharing.csv";

        public class BikeRentalData
        {
            [LoadColumn(0)]
            public float Season { get; set; }
            [LoadColumn(1)]
            public float Month { get; set; }
            [LoadColumn(2)]
            public float Hour { get; set; }
            [LoadColumn(3)]
            public float Holiday { get; set; }
            [LoadColumn(4)]
            public float Weekday { get; set; }
            [LoadColumn(5)]
            public float WorkingDay { get; set; }
            [LoadColumn(6)]
            public float WeatherCondition { get; set; }
            [LoadColumn(7)]
            public float Temperature { get; set; }
            [LoadColumn(8)]
            public float Humidity { get; set; }
            [LoadColumn(9)]
            public float Windspeed { get; set; }
            [LoadColumn(10), ColumnName("Label")]
            public bool RentalType { get; set; } 
        }

        public class RentalTypePrediction
        {
            [ColumnName("PredictedLabel")]
            public bool PredictedRentalType { get; set; }
            public float Probability { get; set; }
            public float Score { get; set; }
        }

        static void Main(string[] args)
        {
            var mlContext = new MLContext(seed: 0);

            // Загрузка данных
            IDataView dataView = mlContext.Data.LoadFromTextFile<BikeRentalData>(
                path: _dataPath,
                hasHeader: true,
                separatorChar: ',');

            //  Разделение данных
            var trainTestSplit = mlContext.Data.TrainTestSplit(dataView, testFraction: 0.2);

            //  Создание пайплайна
            var dataProcessPipeline = mlContext.Transforms
                .Conversion.ConvertType("Label", "Label", DataKind.Boolean)
                .Append(mlContext.Transforms.Categorical.OneHotEncoding(
                    outputColumnName: "SeasonEncoded",
                    inputColumnName: nameof(BikeRentalData.Season)))
                .Append(mlContext.Transforms.Categorical.OneHotEncoding(
                    outputColumnName: "WeatherConditionEncoded",
                    inputColumnName: nameof(BikeRentalData.WeatherCondition)))
                .Append(mlContext.Transforms.Concatenate(
                    "Features",
                    "SeasonEncoded",
                    "WeatherConditionEncoded",
                    nameof(BikeRentalData.Month),
                    nameof(BikeRentalData.Hour),
                    nameof(BikeRentalData.Weekday),
                    nameof(BikeRentalData.Holiday),
                    nameof(BikeRentalData.WorkingDay),
                    nameof(BikeRentalData.Temperature),
                    nameof(BikeRentalData.Humidity),
                    nameof(BikeRentalData.Windspeed)))
                .Append(mlContext.Transforms.NormalizeMinMax("Features"));

            // Обучение моделей
            var logisticRegression = mlContext.BinaryClassification.Trainers.LbfgsLogisticRegression();
            var logisticPipeline = dataProcessPipeline.Append(logisticRegression);
            var logisticModel = logisticPipeline.Fit(trainTestSplit.TrainSet);

            //  Оценка модели
            var predictions = logisticModel.Transform(trainTestSplit.TestSet);
            var metrics = mlContext.BinaryClassification.Evaluate(
                data: predictions,
                labelColumnName: "Label",  
                scoreColumnName: "Score");

            Console.WriteLine($"AUC: {metrics.AreaUnderRocCurve:F2}");
            Console.WriteLine($"F1 Score: {metrics.F1Score:F2}");


            //  Создание prediction engine
            var predictionEngine = mlContext.Model.CreatePredictionEngine<BikeRentalData, RentalTypePrediction>(logisticModel);

            //  Пример предсказания
            var example = new BikeRentalData
            {
                Season = 3,
                Month = 7,
                Hour = 8,
                Holiday = 0,
                Weekday = 1,
                WorkingDay = 1,
                WeatherCondition = 1,
                Temperature = 25,
                Humidity = 50,
                Windspeed = 10
            };

            var prediction = predictionEngine.Predict(example);
            Console.WriteLine($"Prediction: {(prediction.PredictedRentalType ? "Long-term" : "Short-term")}");
            Console.WriteLine($"Probability: {prediction.Probability:P2}");
        }
    }
}