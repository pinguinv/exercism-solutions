import java.nio.charset.StandardCharsets;

class MicroBlog {
    public String truncate(String input) {
        return input.length() > 5 ? input.substring(0, 5) : input;
    }
}