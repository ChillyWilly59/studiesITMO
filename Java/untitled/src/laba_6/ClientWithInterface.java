package laba_6;

class ClientWithInterface extends Human implements BankInfo {
    private String bankName;

    public ClientWithInterface(String name, String surname, String bankName) {
        super(name, surname);
        this.bankName = bankName;
    }

    @Override
    public void infoOutput() {
        System.out.println("Клиент: " + getName() + " " + getSurname());
        printBankName();
    }

    @Override
    public void printBankName() {
        System.out.println("Банк: " + bankName);
    }
}
