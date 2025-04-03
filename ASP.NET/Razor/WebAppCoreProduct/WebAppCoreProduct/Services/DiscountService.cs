namespace WebAppCoreProduct.Services
{
    public class DiscountService
    {
        public decimal CalculateDiscount(decimal? price, double discountPercentage)
        {
            if (price == null || price < 0) return 0;

            return price.Value * (decimal)(discountPercentage / 100);
        }
    }
}
