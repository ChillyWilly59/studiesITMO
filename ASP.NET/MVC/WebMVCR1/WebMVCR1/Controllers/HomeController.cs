using Microsoft.AspNetCore.Mvc;
using WebMVCR1.Models;

namespace WebMVCR1.Controllers
{
    public class HomeController : Controller
    {
        private static PersonRepository db = new PersonRepository();

        //public string Index(string hel) 
        //{
        //    string Greeting = ModelClass.ModelHello() + ", " + hel; 
        //    return Greeting;
        //}


        public ViewResult Index() 
        { 
            int hour = DateTime.Now.Hour; 
            ViewBag.Greeting = hour < 12 ? "Доброе утро" : "Добрый день"; 
            ViewData["Mes"] = "хорошего настроения"; 
            return View(); 
        }
        [HttpPost]
        public ViewResult InputData(Person p)
        {
            db.AddResponse(p);
            return View("Hello", p);
        }
        [HttpGet]
        public ViewResult InputData()
        {
            return View();
        }
        public ViewResult OutputData() 
        { 
            ViewBag.Pers = db.GetAllResponses; 
            ViewBag.Count = db.NumberOfPerson; 
            return View("ListPerson"); 
        }
    }
}
