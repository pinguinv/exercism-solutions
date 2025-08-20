class ComplexNumber {

    private final double real;
    private final double imaginary;

    ComplexNumber(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    double getReal() {
        return this.real;
    }

    double getImaginary() {
        return this.imaginary;
    }

    double abs() {
        return Math.sqrt(Math.pow(this.real, 2) + Math.pow(this.imaginary, 2));
    }

    ComplexNumber add(ComplexNumber other) {
        return new ComplexNumber(this.real + other.real,
                this.imaginary + other.imaginary);
    }

    ComplexNumber subtract(ComplexNumber other) {
        return new ComplexNumber(this.real - other.real, this.imaginary - other.imaginary);
    }

    ComplexNumber multiply(ComplexNumber other) {
        double real = this.real * other.real - this.imaginary * other.imaginary;

        double imaginary = this.imaginary * other.real + this.real * other.imaginary;

        return new ComplexNumber(real, imaginary);
    }

    ComplexNumber divide(ComplexNumber other) {
        final double denominatorOfBoth = Math.pow(other.real, 2) + Math.pow(other.imaginary, 2);

        double real = (this.real * other.real + this.imaginary * other.imaginary)
                / denominatorOfBoth;

        double imaginary = (this.imaginary * other.real - this.real * other.imaginary)
                / denominatorOfBoth;

        return new ComplexNumber(real, imaginary);
    }

    ComplexNumber conjugate() {
        return new ComplexNumber(this.real, -this.imaginary);
    }

    ComplexNumber exponentialOf() {
        double real = Math.exp(this.real) * Math.cos(this.imaginary);
        double imaginary = Math.exp(this.real) * Math.sin(this.imaginary);

        return new ComplexNumber(real, imaginary);
    }
}