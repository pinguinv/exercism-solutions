import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;

public class Gigasecond {

    private final LocalDateTime inGigasecond;

    public Gigasecond(LocalDate moment) {
        inGigasecond = moment.atStartOfDay().plusSeconds(1_000_000_000);
    }

    public Gigasecond(LocalDateTime moment) {
        inGigasecond = moment.plusSeconds(1_000_000_000);
    }

    public LocalDateTime getDateTime() {
        return inGigasecond;
    }
}
