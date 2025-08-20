import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

class AppointmentScheduler {
    private static final DateTimeFormatter appointmentFormatter = DateTimeFormatter.ofPattern("MM/dd/yyyy HH:mm:ss");
    private static final DateTimeFormatter descriptionFormatter = DateTimeFormatter.ofPattern("EEEE, LLLL d, yyyy, 'at' h:mm a.");


    public LocalDateTime schedule(String appointmentDateDescription) {

        return LocalDateTime.parse(appointmentDateDescription, appointmentFormatter);
    }

    public boolean hasPassed(LocalDateTime appointmentDate) {
        return appointmentDate.isBefore(LocalDateTime.now());
    }

    public boolean isAfternoonAppointment(LocalDateTime appointmentDate) {
        int hour = appointmentDate.getHour();
        return hour >= 12 && hour < 18;
    }

    public String getDescription(LocalDateTime appointmentDate) {

        return "You have an appointment on " + descriptionFormatter.format(appointmentDate);
    }

    public LocalDate getAnniversaryDate() {
        return LocalDate.of(LocalDate.now().getYear(), 9, 15);
    }
}
