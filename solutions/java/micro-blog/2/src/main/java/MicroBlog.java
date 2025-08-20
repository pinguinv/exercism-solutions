import java.nio.charset.StandardCharsets;

class MicroBlog {
    public String truncate(String input) {

        StringBuilder sb = new StringBuilder();
        input.codePoints().limit(5).forEach(sb::appendCodePoint);

        return sb.toString();
    }
}