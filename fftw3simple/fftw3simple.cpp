#include <fftw3.h>
#include <stdio.h>
#include <math.h>
#include <Eigen/Dense>

using namespace std::literals;
void generate_sin(const double fc, const double fs, const int size, Eigen::ArrayXcd &data)
{
  const double Ts = 1 / fs; // Sampling Period (sec)

  // Sine wave with frequency fc (Hz)
  for (int n = 0; n < size; n++)
  {
    data[n].real(cos(2 * 3.1415 * fc * n * Ts));
    data[n].imag(sin(2 * 3.1415 * fc * n * Ts));
  }
}

void fft_of_sin(Eigen::ArrayXcd &in_eig, const int fft_size, Eigen::ArrayXcd &out_eig)
{
  fftw_complex *in = reinterpret_cast<fftw_complex *>(in_eig.data());
  fftw_complex *out = reinterpret_cast<fftw_complex *>(out_eig.data());

  fftw_plan p = fftw_plan_dft_1d(fft_size, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

  fftw_execute(p);
  fftw_destroy_plan(p);
}

int main(int argc, char *argv[])
{
  double fs = 200; // Sampling Rate (Samples Per Second)
  double fc = 42;  // Center Frequency (Hz)
  int fft_size = 256;

  Eigen::ArrayXcd in(fft_size);
  Eigen::ArrayXcd out(fft_size);

  generate_sin(fc, fs, fft_size, in);
  fft_of_sin(in, fft_size, out);

  // Print for import into excel (for now)
  for (int n = 0; n < fft_size; n++)
  {
    printf("=complex(%lf,%lf) =complex(%lf,%lf)\n",
           in[n].real(), in[n].imag(),
           out[n].real(), out[n].imag());
  }

  int peak_bin = static_cast<int>((fc / fs) * static_cast<double>(fft_size));
  printf("sizeof(fftw_complex): %ld\n", sizeof(fftw_complex));
  printf("sizeof(Eigen::dcomplex): %ld\n", sizeof(Eigen::dcomplex));
  printf("Expected Peak Bin for %3.1f Hz is: %d\n", fc, peak_bin);
  fftw_cleanup();
  return 0;
}
