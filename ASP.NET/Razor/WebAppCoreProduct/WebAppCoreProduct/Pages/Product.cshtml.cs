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
            MessageRezult = "������� ������ ��� ������� ������.";
        }

        public void OnPost(string name, decimal? price, double discountPercentage)
        {
            Product = new Product();

            if (price == null || price < 0 || string.IsNullOrEmpty(name))
            {
                MessageRezult = "�������� ������������ ������. ��������� ����";
                return;
            }

            var discountAmount = _discountService.CalculateDiscount(price, discountPercentage);
            var finalPrice = price - discountAmount;

            // ���������� ���������
            MessageRezult = $"��� ������ {name} � ����� {price} � ������� {discountPercentage}% ���� �� ������� �������� {finalPrice}.";

            Product.Name = name;
            Product.Price = price;
        }
    }
}
