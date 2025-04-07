namespace MvcCreditApp.Models
{
    public class Bid
    {
        public virtual int BidId { get; set; }
        public virtual string Name { get; set; }
        public virtual string CreditHead { get; set; }
        public virtual DateTime bidDate { get; set; }
    }
}
