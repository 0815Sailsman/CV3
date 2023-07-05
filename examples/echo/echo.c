#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ws.h>
#include <string.h>
#include <time.h>

const char possible[10][20] = {
	"Color",
	"Count",
	"Distance",
	"Info",
	"Log",
	"Debug",
	"Push",
	"Wifi",
	"IR",
	"Hardware"
};

void onopen(ws_cli_conn_t *client) {
	char *cli;
	cli = ws_getaddress(client);
#ifndef DISABLE_VERBOSE
	printf("Connection opened, addr: %s\n", cli);
#endif
}


void onclose(ws_cli_conn_t *client)
{
	char *cli;
	cli = ws_getaddress(client);
#ifndef DISABLE_VERBOSE
	printf("Connection closed, addr: %s\n", cli);
#endif
}


void onmessage(ws_cli_conn_t *client, const unsigned char *msg, uint64_t size, int type) {
	char *cli;
	cli = ws_getaddress(client);
#ifndef DISABLE_VERBOSE
	printf("I receive a message: %s (size: %" PRId64 ", type: %d), from: %s\n",
		msg, size, type, cli);
#endif
	//ws_sendframe(NULL, (char *)msg, size, type);
	const char *literal = "init";
	if (strcmp((const char *)msg, literal) == 0) {
		ws_sendframe_txt(client, "init|Color,Count,Distance,Info,Log");
		// Start spamming random data
		srand(time(NULL));
		int keyInd;
		int val;
		char dataMsg[64];
		while (true) {
			// randomly choose one key
			keyInd = rand() % 10;
			// randomly generate value
			val = rand() % 10;
			// hydrate msg
			sprintf(dataMsg, "data|%s|%d", possible[keyInd], val);
			//send to client
			ws_sendframe_txt(client, dataMsg);
			// Wait for 1 sec
			unsigned int seconds = 1;
			sleep(seconds);
		}
	}
}


int main(void) {
	struct ws_events evs;
	evs.onopen    = &onopen;
	evs.onclose   = &onclose;
	evs.onmessage = &onmessage;
	ws_socket(&evs, 8080, 0, 1000); /* Never returns. */

	/*
	 * If you want to execute code past ws_socket, invoke it like:
	 *   ws_socket(&evs, 8080, 1, 1000)
	 */

	return (0);
}
