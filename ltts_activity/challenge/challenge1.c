// Data Packet Corruption Detection
// In a Wireless communciation device, multiple data packets are transferred over the air.
// It is possible that data might get corrupted or lost before it reaches the destination.
// Create a method to identify if a data packet is corrupted
// Assume below format for the data packet

#define MAX_PACKET_DATA_LENGTH (50)

typedef struct data_packet_t{
    uint8_t id;
    uint8_t data_length;
    uint8_t data[MAX_PACKET_DATA_LENGTH];
    uint16_t crc;
}data_packet_t;


#include <stdio.h>
#include <stdint.h>

#define MAX_PACKET_DATA_LENGTH (50)

typedef struct data_packet_t {
    uint8_t id;
    uint8_t data_length;
    uint8_t data[MAX_PACKET_DATA_LENGTH];
    uint16_t crc;
} data_packet_t;

uint16_t calculateCRC(const data_packet_t* packet) {
    uint16_t crc = 0xFFFF;

    for (int i = 0; i < packet->data_length; i++) {
        crc ^= packet->data[i];

        for (int j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }

    return crc;
}

int isPacketCorrupted(const data_packet_t* packet) {
    uint16_t calculatedCRC = calculateCRC(packet);

    if (calculatedCRC == packet->crc) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    data_packet_t packet;
    packet.id = 1;
    packet.data_length = 4;
    packet.data[0] = 'H';
    packet.data[1] = 'e';
    packet.data[2] = 'l';
    packet.data[3] = 'l';
    packet.crc = 0x4B37;

    int isCorrupted = isPacketCorrupted(&packet);

    if (isCorrupted) {
        printf("Packet is corrupted\n");
    } else {
        printf("Packet is not corrupted\n");
    }

    return 0;
}
