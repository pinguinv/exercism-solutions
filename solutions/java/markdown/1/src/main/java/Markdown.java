class Markdown {

    String parse(String markdown) {
        String[] lines = markdown.split("\n");
        StringBuilder result = new StringBuilder();
        boolean activeList = false;

        for (String line : lines) {

            String theLine = parseHeader(line);

            // If not header
            if (theLine == null) {
                theLine = parseListItem(line);
            }

            // If not list item
            if (theLine == null) {
                theLine = parseParagraph(line);
            }

            boolean isListItem = theLine.matches("(<li>).*");

            // If theLine is a list item and prev line was not one, start list
            if (isListItem && !activeList) {

                activeList = true;
                result.append("<ul>");

            // If theLine is not a list item and prev line was one, end the list
            } else if (!isListItem && activeList) {

                activeList = false;
                result.append("</ul>");
            }

            result.append(theLine);
        }

        // End the list if it is at the end of markdown
        if (activeList) {
            result.append("</ul>");
        }

        return result.toString();
    }

    private String parseHeader(String markdown) {
        int headerSize = 0;

        for (int i = 0; i < markdown.length() && markdown.charAt(i) == '#'; i++) 
        {
            headerSize++;
        }
        
        if (headerSize > 0 && headerSize <= 6) {
            return "<h" + headerSize + ">" + markdown.substring(headerSize + 1) + "</h" + headerSize + ">";
        }

        return null;
    }

    private String parseListItem(String markdown) {
        if (markdown.startsWith("*")) {

            String skipAsterisk = markdown.substring(2);
            String listItemString = parseEmphasis(skipAsterisk);

            return "<li>" + listItemString + "</li>";
        }

        return null;
    }

    private String parseParagraph(String markdown) {
        return "<p>" + parseEmphasis(markdown) + "</p>";
    }

    private String parseEmphasis(String markdown) {
        String lookingFor = "__(.+)__";
        String update = "<strong>$1</strong>";
        String emphasedString = markdown.replaceAll(lookingFor, update);

        lookingFor = "_(.+)_";
        update = "<em>$1</em>";
        emphasedString = emphasedString.replaceAll(lookingFor, update);

        return emphasedString;
    }
}
