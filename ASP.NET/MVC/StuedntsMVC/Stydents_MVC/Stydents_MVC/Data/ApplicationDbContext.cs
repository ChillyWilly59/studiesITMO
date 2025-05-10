using Microsoft.EntityFrameworkCore;
using Stydents_MVC.Models;

public class ApplicationDbContext : DbContext
{
    public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
        : base(options) { }

    public DbSet<Student> Students { get; set; }
}