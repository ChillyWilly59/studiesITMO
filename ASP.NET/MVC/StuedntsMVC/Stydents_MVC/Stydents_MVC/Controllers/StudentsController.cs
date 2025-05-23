﻿// Controllers/StudentsController.cs
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Stydents_MVC.Models;

public class StudentsController : Controller
{
    private readonly ApplicationDbContext _context;

    public StudentsController(ApplicationDbContext context)
    {
        _context = context;
    }

    // GET: Students
    public async Task<IActionResult> Index()
    {
        return View(await _context.Students.ToListAsync());
    }

    // GET: Students/Create
    public IActionResult Create()
    {
        return View();
    }

    // POST: Students/Create
    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Create([Bind("Id,FirstName,LastName,Score,AssessmentDate")] Student student)
    {
        if (ModelState.IsValid)
        {
            _context.Add(student);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }
        return View(student);
    }

    // GET: Students/Edit/5
    public async Task<IActionResult> Edit(int? id)
    {
        if (id == null)
        {
            return NotFound();
        }

        var student = await _context.Students.FindAsync(id);
        if (student == null)
        {
            return NotFound();
        }
        return View(student);
    }

    // POST: Students/Edit/5
    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Edit(int id, [Bind("Id,FirstName,LastName,Score,AssessmentDate")] Student student)
    {
        if (id != student.Id)
        {
            return NotFound();
        }

        if (ModelState.IsValid)
        {
            try
            {
                _context.Update(student);
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!StudentExists(student.Id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }
            return RedirectToAction(nameof(Index));
        }
        return View(student);
    }

    // GET: Students/Delete/5
    public async Task<IActionResult> Delete(int? id)
    {
        if (id == null)
        {
            return NotFound();
        }

        var student = await _context.Students
            .FirstOrDefaultAsync(m => m.Id == id);
        if (student == null)
        {
            return NotFound();
        }

        return View(student);
    }

    // POST: Students/Delete/5
    [HttpPost, ActionName("Delete")]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> DeleteConfirmed(int id)
    {
        var student = await _context.Students.FindAsync(id);
        _context.Students.Remove(student);
        await _context.SaveChangesAsync();
        return RedirectToAction(nameof(Index));
    }

    // GET: Students/Statistics
    public IActionResult Statistics()
    {
        var students = _context.Students.ToList();

        var totalScore = students.Sum(s => s.Score);
        var averageScore = students.Average(s => s.Score);
        var topStudents = students.OrderByDescending(s => s.Score).Take(5).ToList();
        var worstStudents = students.OrderBy(s => s.Score).Take(5).ToList();

        ViewBag.TotalScore = totalScore;
        ViewBag.AverageScore = averageScore;
        ViewBag.TopStudents = topStudents;
        ViewBag.WorstStudents = worstStudents;

        return View();
    }

    // GET: Students/Export
    public async Task<IActionResult> Export()
    {
        var students = await _context.Students.OrderByDescending(s => s.Score).ToListAsync();

        string content = "Список студентов с результатами:\n\n";
        content += "№\tФИО\t\tБаллы\tДата оценки\n";

        int i = 1;
        foreach (var student in students)
        {
            content += $"{i++}\t{student.LastName} {student.FirstName}\t{student.Score}\t{student.AssessmentDate:dd.MM.yyyy}\n";
        }

        byte[] bytes = System.Text.Encoding.UTF8.GetBytes(content);
        return File(bytes, "text/plain", "students_results.txt");
    }

    private bool StudentExists(int id)
    {
        return _context.Students.Any(e => e.Id == id);
    }
}