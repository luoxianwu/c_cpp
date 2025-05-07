#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

HANDLE hSerial;

int uart_init(const char *portName) {
    hSerial = CreateFileA(portName,
        GENERIC_READ | GENERIC_WRITE,
        0, NULL, OPEN_EXISTING, 0, NULL);

    if (hSerial == INVALID_HANDLE_VALUE) {
        printf("Error opening serial port\n");
        return -1;
    }

    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) {
        printf("Error getting state\n");
        CloseHandle(hSerial);
        return -1;
    }

    dcbSerialParams.BaudRate = CBR_115200;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        printf("Error setting state\n");
        CloseHandle(hSerial);
        return -1;
    }

    COMMTIMEOUTS timeouts = { 0 };
    timeouts.ReadIntervalTimeout = MAXDWORD;
    timeouts.ReadTotalTimeoutConstant = 0;
    timeouts.ReadTotalTimeoutMultiplier = 0;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;

    SetCommTimeouts(hSerial, &timeouts);
    return 0;
}

bool uart_getc(char *out_char) {
    DWORD bytesRead;
    if (ReadFile(hSerial, out_char, 1, &bytesRead, NULL) && bytesRead == 1) {
        return true;  // Data received
    }
    return false;     // No data
}

void uart_putc(char c) {
    DWORD bytesWritten;
    WriteFile(hSerial, &c, 1, &bytesWritten, NULL);
}

void uart_puts(const char *data, size_t len) {
    DWORD bytesWritten;
    WriteFile(hSerial, data, (DWORD)len, &bytesWritten, NULL);
}

void uart_close() {
    CloseHandle(hSerial);
}

int main() {
    if (uart_init("\\\\.\\COM5") == 0) {
        const char *msg = "Hello from PC over UART!\r\n";
        uart_puts(msg, strlen(msg));

        printf("Waiting for incoming data (5 seconds)...\n");

        DWORD start = GetTickCount();
        char c;
        printf("Received...:\n");
        while (GetTickCount() - start < 1000) { // 5 second window
            if (uart_getc(&c)) {
                printf("%c", c);
            }
            Sleep(1); // avoid tight loop
        }

        uart_close();
    }
    return 0;
}

/*
C:\Users\xianw\c [main ≡ +2 ~0 -0 !]> .\a.exe
Waiting for incoming data (5 seconds)...
Received...:
Hello from PC over UART!
C:\Users\xianw\c [main ≡ +2 ~0 -0 !]>
*/