#define FIFO_DATA     (*(unsigned char *) 0x1000)
#define FIFO_STATUS   (*(unsigned char *) 0x1001)

#define TX_FIFO_FULL  (FIFO_STATUS & 0x01)
#define RX_FIFO_EMPTY (FIFO_STATUS & 0x02)

extern void wait ();
extern void __fastcall__ rs232_tx (char *str);

int main () {
  while (1) {                                     //  Run forever
    wait ();                                      //  Wait for an RX FIFO interrupt

    while (RX_FIFO_EMPTY == 0) {                  //  While the RX FIFO is not empty
      if (FIFO_DATA == '?') {                     //  Does the RX character = '?'
        rs232_tx ("Hello World!");                //  Transmit "Hello World!"
      }                                           //  Discard any other RX characters
    }
  }

  return (0);                                     //  We should never get here!
}

