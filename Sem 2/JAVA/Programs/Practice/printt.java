interface printable{
    void print();
    
}

public class printt implements printable
{
    public void print()
    {
        System.out.println("Hello");
    }
        
        public static void main(String[] args)
        {
            printt obj = new printt();
            obj.print();

        }
}