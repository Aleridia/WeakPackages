package WeakPackageId;

import java.io.*;

public class InsecureDeserialization {

    // A field to hold a value of generic type T
    private String maliciousInput;

    // Constructor to initialize the generic value
    public InsecureDeserialization(String maliciousInput) {
        this.maliciousInput = maliciousInput;
    }

    // A method to retrieve the value
    public String getMaliciousInput() {
        return maliciousInput;
    }

    public void deserializeData() throws Exception {
        // Simulate deserialization of untrusted input
        ObjectInputStream in = new ObjectInputStream(new FileInputStream("maliciousObject.ser"));
        Object obj = in.readObject(); // Could execute malicious code
        in.close();
        System.out.println("Object: " + obj);
    }
}

