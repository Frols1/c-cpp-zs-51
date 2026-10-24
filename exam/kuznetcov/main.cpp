#include <iostream>
#include <iomanip>


int main()
    {
        const int N = 12;
        int snr[N] = {42, 38, 25, 17, 33, 45, 29, 12, 36, 41, 22, 30};
        int maxVal = snr[0], maxIdx = 0;
        int minVal = snr[0], minIdx = 0;
        int sum = 0;
        int cnt35 = 0;
        int cnt20 = 0;
        int cntBad = 0;

        for (int i=0;i<N;++i) {
            if (snr[i] > maxVal) {maxVal = snr[i]; maxIdx = i;}
            if (snr[i] < minVal) {minVal = snr[i]; minIdx = i;}
            sum += snr[i];
        }

        double avg = static_cast<double>(sum) / N;

        for (int i=0;i<N;++i) {
            if (snr[i]>=35) {cnt35++;}
            if (snr[i]>=20) {cnt20++;}
            else {cntBad++;}
        }

        std::cout << "===== Отчёт по соте Wi-Fi (N=" << N << ") =====" << "\n";
        std::cout << "Минимальный SNR : " << minVal << " дБ (клиент " << std::setw(2) << std::setfill('0') << minIdx << ")";
        if (minVal>=35) std::cout << " — Отличный" << "\n";
        else if (minVal>=20) std::cout << " — Хороший" << "\n";
        else std::cout << " — Плохой" << "\n";

        std::cout << "Максимальный SNR: " << maxVal << " дБ (клиент " << std::setw(2) << std::setfill('0') << maxIdx << ")";
        if (maxVal>=35) std::cout << " — Отличный" << "\n";
        else if (maxVal>=20) std::cout << " — Хороший" << "\n";
        else std::cout << " — Плохой" << "\n";

        std::cout << "Средний SNR : " << std::fixed << std::setprecision(2) << avg << " дБ" << "\n";
        std::cout << "--------------------------------------" << "\n";
        std::cout << "Клиентов с SNR >= 35 дБ : " << cnt35 << "\n";
        std::cout << "Клиентов с SNR >= 20 дБ : " << cnt20 << "\n";
        std::cout << "Клиентов с SNR < 20 дБ : " << cntBad;
        if (cntBad>0) std::cout << " <-- требуют внимания";
        std::cout << "\n";
        std::cout << "--------------------------------------" << "\n";
        std::cout << "Разброс (max-min) : " << maxVal-minVal << " дБ" << "\n";

        if (cntBad==0)
        std::cout << "Оценка соты: хорошая, проблемных клиентов нет" << "\n";
        else if (cntBad<=3)
        std::cout << "Оценка соты: рабочая, но есть проблемные клиенты" << "\n";
        else
        std::cout << "Оценка соты: плохая, много клиентов со слабым сигналом" << "\n";

        return 0;
    }
