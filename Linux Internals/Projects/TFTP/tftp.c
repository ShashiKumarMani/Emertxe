/*############################################################################################### 
 *
 *           Author         : 
 *           Date           : 
 *           File           : tftp.c©
 *           Descriptions   : function to create/extract packets before/after sending/receving
 *           Objective      : Packet creation and extraction
 *           Usage          :
 *           Output         :
 *
###############################################################################################*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include "tftp.h"
#include "file.h"

/* tftp protocol implementation 
 * Both server and client must use this file for sen/receive data
 */

int packet_parse()
{
	
}

void packet_free(packet_t *data_packet)
{
	memset(data_packet, 0, sizeof(*data_packet));
}


/* Function to create a read request packet */
void packet_form_rrq(packet_t *data_packet, char *filename)
{
	data_packet->opcode = OPCODE_RRQ;
	strcpy(data_packet->filename, filename);
	strcpy(data_packet->mode, MODE_NETASCII);
}

/* Function to create a write request packet */
void packet_form_wrq(packet_t *data_packet, char *filename)
{
    data_packet->opcode = OPCODE_WRQ;
    strcpy(data_packet->filename, filename);
    strcpy(data_packet->mode, MODE_NETASCII);
}

void packet_form_data(packet_t *data_packet, int pack_num)
{
	data_packet->opcode = OPCODE_DATA;
	data_packet->blocknum = pack_num;
}

void packet_form_ack(packet_t *data_packet)
{
	data_packet->opcode = OPCODE_ACK;
}

void packet_form_error(packet_t *data_packet)
{
	data_packet->opcode = OPCODE_ERROR;  
    data_packet->ecode = ECODE_1;
    strcpy(data_packet->estring, ESTRING_1);
    data_packet->estring_length = strlen(ESTRING_1);
}

