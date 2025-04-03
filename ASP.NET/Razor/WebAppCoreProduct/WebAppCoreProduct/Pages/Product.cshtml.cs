using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using WebAppCoreProduct.Models;
using WebAppCoreProduct.Services; 

namespace WebAppCoreProduct.Pages
{
    public class ProductModel : PageModel
    {
        private readonly DiscountService _discountService; 
        public ProductModel(DiscountService discountService)
        {
            _discountService = discountService;
        }

        public string MessageRezult { get; private set; }
        public Product Product { get; set; }

        public void OnGet()
        {
            MessageRezult = "Введите данные для расчета скидки.";
        }

        public void OnPost(string name, decimal? price, double discountPercentage)
        {
            Product = new Product();

            if (price == null || price < 0 || string.IsNullOrEmpty(name))
            {
                MessageRezult = "Переданы некорректные данные. Повторите ввод";
                return;
            }

            var discountAmount = _discountService.CalculateDiscount(price, discountPercentage);
            var finalPrice = price - discountAmount;

            // Отображаем результат
            MessageRezult = $"Для товара {name} с ценой {price} и скидкой {discountPercentage}% цена со скидкой составит {finalPrice}.";

            Product.Name = name;
            Product.Price = price;
        }
    }
}
