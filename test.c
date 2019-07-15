
//CprogramtoImplementPing

//compileas-oping
//runassudo./ping<hostname>

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

//DefinethePacketConstants
//pingpacketsize
#definePING_PKT_S64

//Automaticportnumber
#definePORT_NO0

//Automaticportnumber
#definePING_SLEEP_RATE1000000x

//Givesthetimeoutdelayforreceivingpackets
//inseconds
#defineRECV_TIMEOUT1

//DefinethePingLoop
intpingloop = 1;

//pingpacketstructure
structping_pkt
{
	structicmphdrhdr;
	charmsg[PING_PKT_S - sizeof(structicmphdr)];
};

//CalculatingtheCheckSum
unsignedshortchecksum(void *b, intlen)
{
	unsignedshort *buf = b;
	unsignedintsum = 0;
	unsignedshortresult;

	for (sum = 0; len > 1; len -= 2)
		sum += *buf++;
	if (len == 1)
		sum += *(unsignedchar *)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	result = ~sum;
	returnresult;
}

//Interrupthandler
voidintHandler(intdummy)
{
	pingloop = 0;
}

//PerformsaDNSlookup
char *dns_lookup(char *addr_host, structsockaddr_in *addr_con)
{
	printf("\nResolvingDNS..\n");
	structhostent *host_entity;
	char *ip = (char *)malloc(NI_MAXHOST * sizeof(char));
	inti;

	if ((host_entity = gethostbyname(addr_host)) == NULL)
	{
		//Noipfoundforhostname
		returnNULL;
	}

	//fillingupaddressstructure
	strcpy(ip, inet_ntoa(*(structin_addr *)
							  host_entity->h_addr));

	(*addr_con).sin_family = host_entity->h_addrtype;
	(*addr_con).sin_port = htons(PORT_NO);
	(*addr_con).sin_addr.s_addr = *(long *)host_entity->h_addr;

	returnip;
}

//Resolvesthereverselookupofthehostname
char *reverse_dns_lookup(char *ip_addr)
{
	structsockaddr_intemp_addr;
	socklen_tlen;
	charbuf[NI_MAXHOST], *ret_buf;

	temp_addr.sin_family = AF_INET;
	temp_addr.sin_addr.s_addr = inet_addr(ip_addr);
	len = sizeof(structsockaddr_in);

	if (getnameinfo((structsockaddr *)&temp_addr, len, buf,
					sizeof(buf), NULL, 0, NI_NAMEREQD))
	{
		printf("Couldnotresolvereverselookupofhostname\n");
		returnNULL;
	}
	ret_buf = (char *)malloc((strlen(buf) + 1) * sizeof(char));
	strcpy(ret_buf, buf);
	returnret_buf;
}

//makeapingrequest
voidsend_ping(intping_sockfd, structsockaddr_in *ping_addr,
			  char *ping_dom, char *ping_ip, char *rev_host)
{
	int ttl_val = 64, msg_count = 0, i, addr_len, flag = 1,
	msg_received_count = 0;

	struct ping_pktpckt;
	struct cockaddr_inr_addr;
	struct timespec time_start, time_end, tfs, tfe;
	long double rtt_msec = 0, total_msec = 0;
	struct timeval tv_out;
	tv_out.tv_sec = RECV_TIMEOUT;
	tv_out.tv_usec = 0;

	clock_gettime(CLOCK_MONOTONIC, &tfs);

	//setsocketoptionsatiptoTTLandvalueto64,
	//changetowhatyouwantbysettingttl_val
	if (setsockopt(ping_sockfd, SOL_IP, IP_TTL,
				   &ttl_val, sizeof(ttl_val)) != 0)
	{
printf("\nSettingsocketoptions
toTTLfailed!\n");
return;
	}

	else
	{
		printf("\nSocketsettoTTL..\n");
	}

	//settingtimeoutofrecvsetting
	setsockopt(ping_sockfd, SOL_SOCKET, SO_RCVTIMEO,
			   (constchar *)&tv_out, sizeoftv_out);

	//sendicmppacketinaninfiniteloop
	while (pingloop)
	{
		//flagiswhetherpacketwassentornot
		flag = 1;

		//fillingpacket
		bzero(&pckt, sizeof(pckt));

		pckt.hdr.type = ICMP_ECHO;
		pckt.hdr.un.echo.id = getpid();

		for (i = 0; i < sizeof(pckt.msg) - 1; i++)
			pckt.msg[i] = i + '0';

		pckt.msg[i] = 0;
		pckt.hdr.un.echo.sequence = msg_count++;
		pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

		usleep(PING_SLEEP_RATE);

		//sendpacket
		clock_gettime(CLOCK_MONOTONIC, &time_start);
		if (sendto(ping_sockfd, &pckt, sizeof(pckt), 0,
				   (structsockaddr *)ping_addr,
				   sizeof(*ping_addr)) <= 0)
		{
			printf("\nPacketSendingFailed!\n");
			flag = 0;
		}

		//receivepacket
		addr_len = sizeof(r_addr);

		if (recvfrom(ping_sockfd, &pckt, sizeof(pckt), 0,
					 (structsockaddr *)&r_addr, &addr_len) <= 0 &&
			msg_count > 1)
		{
			printf("\nPacketreceivefailed!\n");
		}

		else
		{
			clock_gettime(CLOCK_MONOTONIC, &time_end);

			doubletimeElapsed = ((double)(time_end.tv_nsec -
										  time_start.tv_nsec)) /
								1000000.0rtt_msec = (time_end.tv_sec -
													 time_start.tv_sec) *
														1000.0 +
													timeElapsed;

			//ifpacketwasnotsent,don'treceive
			if (flag)
			{
				if (!(pckt.hdr.type == 69 && pckt.hdr.code == 0))
				{
					printf("Error..PacketreceivedwithICMP
							   type %
							   dcode % d\n ",
									   pckt.hdr.type,
						   pckt.hdr.code);
				}
				else
				{
					printf("%dbytesfrom%s(h:%s)
						   (% s) msg_seq = % dttl = % d
														  rtt = % Lfms.\n ",
																  PING_PKT_S,
						   ping_dom, rev_host, ping_ip, msg_count, ttl_val, rtt_msec);

					msg_received_count++;
				}
			}
		}
	}
	clock_gettime(CLOCK_MONOTONIC, &tfe);
	doubletimeElapsed = ((double)(tfe.tv_nsec - tfs.tv_nsec)) / 1000000.0;
	total_msec = (tfe.tv_sec - tfs.tv_sec) * 1000.0 + timeElapsed;
	printf("\n===%spingstatistics===\n", ping_ip);
	printf("\n%dpacketssent,%dpacketsreceived,%fpercentpacketloss.Totaltime:%Lfms.\n\n", msg_count, msg_received_count, ((msg_count - msg_received_count) / msg_count) * 100.0, total_msec);
}

//DriverCode
intmain(intargc, char *argv[])
{
	int sockfd;
	char *ip_addr, *reverse_hostname;
	struct sockaddr_in addr_con;
	int addrlen = sizeof(addr_con);
	char net_buf[NI_MAXHOST];

	if (argc != 2)
	{
		printf("\nFormat%s<address>\n", argv[0]);
		return0;
	}

	ip_addr = dns_lookup(argv[1], &addr_con);
	if (ip_addr == NULL)
	{
		printf("\nDNSlookupfailed!Couldnotresolvehostname!\n");
		return0;
	}

	reverse_hostname = reverse_dns_lookup(ip_addr);
	printf("\nTryingtoconnectto'%s'IP:%s\n", argv[1], ip_addr);
	printf("\nReverseLookupdomain:%s", reverse_hostname);

	//socket()
	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0)
	{
		printf("\nSocketfiledescriptornotreceived!!\n");
		return0;
	}
	else
		printf("\nSocketfiledescriptor%dreceived\n", sockfd);

	signal(SIGINT, intHandler); //catchinginterrupt

	//sendpingscontinuously
	send_ping(sockfd, &addr_con, reverse_hostname, ip_addr, argv[1]);

	return0;
}
