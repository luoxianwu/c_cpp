import serial
import time

ser = None

def uart_init(port="COM5", baudrate=115200, timeout=0):
    global ser
    ser = serial.Serial(
        port=port,
        baudrate=baudrate,
        timeout=timeout  # 0 = non-blocking, None = blocking
    )

def uart_close():
    if ser and ser.is_open:
        ser.close()

def uart_putc(c):
    if ser and ser.is_open:
        ser.write(c.encode('utf-8'))

def uart_puts(data: bytes):
    if ser and ser.is_open:
        ser.write(data)

def uart_getc():
    if ser and ser.is_open and ser.in_waiting:
        return True, ser.read(1).decode('utf-8', errors='ignore')
    return False, None

# --- Example usage ---
if __name__ == "__main__":
    uart_init(port="COM5", baudrate=9600, timeout=0)

    uart_puts(b"Hello, UART!\r\n")
    print("Waiting for input (press key on UART)...")

    for _ in range(100):  # Poll for ~10 seconds
        ok, ch = uart_getc()
        if ok:
            print(f"Received: {ch}")
            break
        time.sleep(0.1)

    uart_close()
