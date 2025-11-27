document.addEventListener('DOMContentLoaded', () => {

    const locationBtn = document.getElementById('getLocationBtn');
    const locationOutput = document.getElementById('locationOutput');
    const mapContainer = document.getElementById('mapContainer');

    if (locationBtn && locationOutput && mapContainer) {

        locationBtn.addEventListener('click', () => {
            locationOutput.textContent = "Попытка определить местоположение...";
            getLocation();
        });

        function getLocation() {
            if (navigator.geolocation) {
                navigator.geolocation.getCurrentPosition(showPosition, handleError, {
                    enableHighAccuracy: true,
                    timeout: 5000,
                    maximumAge: 0
                });
            } else {
                locationOutput.textContent = "Ваш браузер не поддерживает Geolocation API.";
            }
        }

        function showPosition(position) {
            const lat = position.coords.latitude;
            const lon = position.coords.longitude;
            const accuracy = position.coords.accuracy;

            locationOutput.innerHTML = `
                <p><strong>Ваше местоположение определено!</strong></p>
                <p>Широта: ${lat.toFixed(6)}°</p>
                <p>Долгота: ${lon.toFixed(6)}°</p>
                <p>Точность: около ${Math.round(accuracy)} метров</p>
                <p><em>(Данные предоставлены вашим устройством и браузером)</em></p>
            `;

            mapContainer.innerHTML = `
                <a href="https://www.google.com/maps/search/?api=1&query=${lat},${lon}" target="_blank" style="color: #a0c3ff;">Показать на Google Картах</a>
            `;
        }

        function handleError(error) {
            let message = '';
            switch(error.code) {
                case error.PERMISSION_DENIED:
                    message = "Вы отказали в доступе к геолокации. Для работы функции необходимо разрешение.";
                    break;
                case error.POSITION_UNAVAILABLE:
                    message = "Информация о местоположении недоступна (например, из-за слабого сигнала).";
                    break;
                case error.TIMEOUT:
                    message = "Время ожидания истекло. Попробуйте снова.";
                    break;
                case error.UNKNOWN_ERROR:
                default:
                    message = "Произошла неизвестная ошибка.";
                    break;
            }
            locationOutput.textContent = `Ошибка Geolocation: ${message}`;
            console.error("Geolocation Error:", error);
        }
    }

    const ratingInput = document.getElementById('rating');
    const ratingValueOutput = document.getElementById('ratingValue');

    if (ratingInput && ratingValueOutput) {
        ratingInput.addEventListener('input', () => {
            ratingValueOutput.value = ratingInput.value;
        });
    }

});