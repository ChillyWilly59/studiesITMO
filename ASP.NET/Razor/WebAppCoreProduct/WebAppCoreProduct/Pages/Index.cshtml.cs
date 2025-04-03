using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using WebAppCoreProduct.Models;

namespace WebAppCoreProduct.Pages
{
    public class IndexModel : PageModel
    {
        public bool IsCorrect { get; set; } = true;
        public Product Product { get; set; }
        public string MessageRezult { get; private set; }

        public void OnGet(string name, decimal? price)
        {
            Product = new Product();
            if (price == null || price < 0 || string.IsNullOrEmpty(name))
            {
                IsCorrect = false;
                return;
            }

            Product.Price = price;
            Product.Name = name;
        }
        public void OnPost(string name, decimal? price)
        {
            Product = new Product();
            if (price == null || price < 0 || string.IsNullOrEmpty(name))
            {
                MessageRezult = "Переданы некорректные данные. Повторите ввод";
                return;
            }

            var result = price * (decimal?)0.18;
            MessageRezult = $"Для товара {name} с ценой {price} скидка получится {result}";

            Product.Price = price;
            Product.Name = name;
        }

    }
}
