document.addEventListener('DOMContentLoaded', () => {
    const locationBtn = document.getElementById('getLocationBtn');
    const locationOutput = document.getElementById('locationOutput');

    if (locationBtn) {
        locationBtn.addEventListener('click', () => {
            locationOutput.textContent = "Попытка определить местоположение...";
            getLocation();
        });
    }

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
        const lat = position.coords.latitude; // Широта
        const lon = position.coords.longitude; // Долгота
        const accuracy = position.coords.accuracy; // Точность в метрах

        locationOutput.innerHTML = `
            <p><strong>Ваше местоположение определено!</strong></p>
            <p>Широта: ${lat}°</p>
            <p>Долгота: ${lon}°</p>
            <p>Точность: около ${Math.round(accuracy)} метров</p>
            <p><em>(Данные предоставлены вашим устройством и браузером)</em></p>
        `;

        const mapContainer = document.getElementById('mapContainer');
        mapContainer.innerHTML = `
            <a href="https://maps.google.com/?q=${lat},${lon}" target="_blank" style="color: #a0c3ff;">Показать на Google Картах</a>
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
                message = "Произошла неизвестная ошибка.";
                break;
        }
        locationOutput.textContent = `Ошибка Geolocation: ${message}`;
        console.error("Geolocation Error:", error);
    }
});