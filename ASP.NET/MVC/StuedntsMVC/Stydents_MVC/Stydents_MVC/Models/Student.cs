using System.ComponentModel.DataAnnotations;

namespace Stydents_MVC.Models;
public class Student
{
    public int Id { get; set; }

    [Required(ErrorMessage = "Имя обязательно")]
    [Display(Name = "Имя")]
    public string FirstName { get; set; }

    [Required(ErrorMessage = "Фамилия обязательна")]
    [Display(Name = "Фамилия")]
    public string LastName { get; set; }

    [Range(0, 100, ErrorMessage = "Баллы должны быть от 0 до 100")]
    [Display(Name = "Баллы")]
    public int Score { get; set; }

    private DateTime _assessmentDate;

    [Display(Name = "Дата оценки")]
    public DateTime AssessmentDate
    {
        get => _assessmentDate;
        set => _assessmentDate = value.Kind == DateTimeKind.Unspecified
            ? DateTime.SpecifyKind(value, DateTimeKind.Utc)
            : value.ToUniversalTime();
    }
}