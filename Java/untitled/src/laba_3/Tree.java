package laba_3;

public class Tree {
    private int age;
    private boolean isAlive;
    private String name;

    public Tree(int age,String name){
        this.age = age;
        this.name = name;
        this.isAlive = true;
    }

    public Tree(int age, String name, boolean isAlive) {
        this.name = name;
        this.age = age;
        this.isAlive = isAlive;
    }

    public Tree(){
        System.out.println("Пустой конструктор без параметров сработал!");
    }

    public void printInfo(){
        System.out.println("Название дерева: " + name);
        System.out.println("Возраст: " + age);
        System.out.println("Живое: " + (isAlive ? "Да" : "Нет"));
        System.out.println(" ");
    }

    public static void main(String[] args) {
        Tree tree = new Tree(100,"Дуб");
        tree.printInfo();

        Tree tree1 = new Tree(150,"Береза", false);
        tree1.printInfo();

        Tree tree2 = new Tree();
        tree2.printInfo();
    }
}
