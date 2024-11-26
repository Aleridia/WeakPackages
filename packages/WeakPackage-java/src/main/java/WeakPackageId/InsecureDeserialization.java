import java.io.*;

public class InsecureDeserialization {
    public static void main(String[] args) throws Exception {
        // Simulate deserialization of untrusted input
        ObjectInputStream in = new ObjectInputStream(new FileInputStream("maliciousObject.ser"));
        Object obj = in.readObject(); // Could execute malicious code
        in.close();
        System.out.println("Object: " + obj);
    }
}
