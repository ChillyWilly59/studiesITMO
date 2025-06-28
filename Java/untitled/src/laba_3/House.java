package laba_3;

public class House {
    private int numberFloors;
    private int constructionYear;
    private String name;

    public void meaning(int numberFloors, int constructionYear, String name) {
        this.numberFloors = numberFloors;
        this.constructionYear = constructionYear;
        this.name = name;
    }

    public int sinceConstructionYear(){
      int thisYear = java.time.Year.now().getValue();
      return thisYear - constructionYear;
    }

    public void conclusion(){
        System.out.println("Наименование: " + name);
        System.out.println("Количество этажей: " + numberFloors);
        System.out.println("Год постройки: " + constructionYear);
        System.out.println("Возраст дома: " + sinceConstructionYear() + " лет");

    }

    public static void main(String[] args) {
        House house = new House();
        house.meaning(10,2005,"ЖК Орленок");

        House house1 = new House();
        house1.meaning(15,2010,"Бизнес центр Любятово");


        house.conclusion();
        house1.conclusion();
    }
}
