package laba_6;

class BankEmployee extends Human {
    private String bankName;

    public BankEmployee(String name, String surname, String bankName) {
        super(name, surname);
        this.bankName = bankName;
    }

    public void infoOutput() {
        System.out.println("Работник: " + getName() + " " + getSurname());
        System.out.println("Банк: " + bankName);
    }
}