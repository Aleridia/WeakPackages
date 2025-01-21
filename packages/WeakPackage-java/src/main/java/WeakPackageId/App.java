package WeakPackageId;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        InsecureDeserialization insecure = new InsecureDeserialization("oui");
        System.out.println( "Hello World!" );
    }
}
