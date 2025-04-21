using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace MvcCreditApp.Models
{
    public class Credit
    {
        public virtual int CreditId { get; set; }

        [DisplayName("Название кредита")]
        [Required(ErrorMessage = "Поле 'Название кредита' обязательно для заполнения")]
        public virtual string Head { get; set; }

        [DisplayName("Срок (мес.)")]
        [Required(ErrorMessage = "Поле 'Срок' обязательно для заполнения")]
        public virtual int Period { get; set; }

        [DisplayName("Сумма")]
        [Required(ErrorMessage = "Поле 'Сумма' обязательно для заполнения")]
        public virtual int Sum { get; set; }

        [DisplayName("Процентная ставка")]
        [Required(ErrorMessage = "Поле 'Процентная ставка' обязательно для заполнения")]
        public virtual int Procent { get; set; }
    }
}
