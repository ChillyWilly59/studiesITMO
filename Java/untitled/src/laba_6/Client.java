package laba_6;

class Client extends Human{
    public String bankName;

    public Client(String name, String surname, String bankName) {
        super(name, surname);
        this.bankName = bankName;
    }

    @Override
    public void infoOutput() {
        System.out.println("Клиент: " + getName() + " " + getSurname());
        System.out.println("Банк: " + bankName);
    }
}