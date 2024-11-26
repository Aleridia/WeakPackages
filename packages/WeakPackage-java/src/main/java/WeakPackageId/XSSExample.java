import javax.servlet.http.*;
import java.io.IOException;

public class XSSExample extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String userInput = request.getParameter("name");
        response.getWriter().println("<html><body>Welcome, " + userInput + "</body></html>"); // Unsanitized input
    }
}