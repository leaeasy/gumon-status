/*Options*/


#define ALSA /*If defined it monitors a mixer status and volume*/
#define TIMER 1 /*Update the data every TIMER seconds*/
#define BATTERY

#define BATTERY_TIMER 100 /*Update the Battery data every BATTERY_TIMER seconds*/

/*CPUs*/
static const char *cpus_load[] = {"cpu"}; /*cpus in /proc/cpustats to monitor*/
static const char *cpusf_load[][3] = { {"^fg(#222222)^bg(#228b22)   ^fg(#FFFFFF)^bg(#228b22)   ^fg(#FFFFFF)%3.0f %% ^bg()^fg(#228b22)^bg(#C5C1AA)   ",           
                   "^fg(#222222)^bg(#FFB917)   ^fg(#FFFFFF)^bg(#FFB917)   ^fg(#FFFFFF)%3.0f %% ^bg()^fg(#FFB917)^bg(#C5C1AA)   ", 
                   "^fg(#222222)^bg(#FF1778)   ^fg(#FFFFFF)^bg(#FF1778)   ^fg(#FFFFFF)%3.0f %% ^bg()^fg(#FF1778)^bg(#C5C1AA)   ", 
				   }}; /*CPUs format [Low,Norm,High]*/
static const float cpusthres_load[][2] = { {25.,75.} };

/*MEM&SWAP*/
static const char memf[] = "^fg(#4D4D4D)   ^fg(#545454)%.1f  %.0lfMB  ^fg(#C5C1AA)^bg(#657b82)   "; /*Memory format*/

/*Network*/
static const char *netIFS[] = {"wlp6s0","enp8s0"}; /*Network IFs to monitor, will be shown only if connected*/

static const char *netIFSfdown[][3] = { {"^fg(#3399FF)        ^fg(#FFFFFF)    %.1fKB  ",
					 "^fg(#3399FF)      ^bg(#FFB917)^fg(#00FFFF) %.1fKB   ",
					 "^fg(#3399FF)      ^bg(#FF1778)^fg(#00FFFF) %.1fKB   "}, 
			  	        {"^fg(#3399FF)          ^fg(#FFFFFF)    %.1fKB  ",
					 "^fg(#3399FF)      ^bg(#FFB917)^fg(#00FFFF) %.1fKB   ",
					 "^fg(#3399FF)      ^bg(#FF1778)^fg(#00FFFF) %.1fKB   "} }; /*Download speed KB/s formats*/
static const float netIFSdthres[][2] = { {300.,600.}, /*Network IFs download thresholds in KB/s*/
					 {300.,600.} };

static const char *netIFSfup[][3] = { {"^bg(#657b82)^fg(#FFFFFF) ^fg(#FFFFFF)%.1fKB   ^fg(#657b82)^bg(#C5C1AA)   ",
				       "^bg(#FFB917)^fg(#0FFF00)%.1fKB   ^fg(#657b82)^bg(#C5C1AA)   ",
				       "^bg(#FF1778)^fg(#0FFF00)%.1fKB   ^fg(#657b82)^bg(#C5C1AA)   "}, /*Upload speed in KB/s formats*/
				      {"^bg(#657b82)^fg(#FFFFFF)%.1fKB   ^fg(#657b82)^bg(#C5C1AA)   ",
				       "^bg(#FFB917)^fg(#0FFF00)%.1fKB   ^fg(#657b82)^bg(#C5C1AA)   ",
				       "^bg(#FF1778)^fg(#0FFF00)%.1fKB   ^fg(#657b82)^bg(#C5C1AA)   "} };

static const float netIFSuthres[][2] = { {300.,600.}, /*Network IFs upload thresholds in KB/s*/
					 {300.,600.} };

static const char WSSf[] = {"  ^fg(#FFB917) ^fg(#545454)%.2f  ^fg(#C5C1AA)^bg(#657b82)   "};/*If the Net IF is wireless, the signal strenght 
							   is printed along, this is the format of the 
							   signal strenght >=0.00 <=1.00*/ 

#ifdef ALSA
/*Audio*/
const static char soundcard[] =  "default"; /*Soundcard to monitor*/
const static char mixername[] =  "Master"; /*Mixer to monitor*/
const static char *volumestatus[] = {"  ^fg(#AAAAAA) ","  ^fg(#FFFFFF) "}; /*Volume status 1.Mute 2.Normal*/
const static char volumef[] = "%s ^fg(#FFFFFF)%.0f%  ";/*Volume format (status and volume level in % */
#endif

/*Time*/
static const char timef[] = " ^fg(#3399FF)  ^fg(#FF1778)%a %d/%m/%y ^fg(#228B22) %H:%M:%S  ";/*Time format, see man strftime*/

/*Temperature reading*/
static const char *temperatures[] = {"temp2_input"}; /*files in /sys/devices/platform/coretemp.0/ to monitor*/
static const char *temperaturesf[][3] = { 
					  {"^fg(#C5C1AA)^bg(#228B22)   ^fg(#FFFFFF) ^fg(#FFFFFF)%.0f°  ",
					   "^fg(#C5C1AA)^bg(#FFB917)   ^fg(#FFFFFF) ^bg(#FFB917)^fg(#FFFFFF)%.0f°  ",
					   "^fg(#C5C1AA)^bg(#FF1778)   ^fg(#FFFFFF) ^bg(#FF1778)^fg(#FFFFFF)%.0f°  "} }; /*Temps format*/

static const float temperaturesthres[][2] = { {60.,90.}, /*Temps thresholds in degrees celsius*/
					      };


#ifdef BATTERY
/*BATTERY*/
static const char battery[] = "BAT1"; /*folder in /sys/class/power_supply */
static const char *batteryf[3] = {"  ^fg(#657b82)^bg(#FF1778)    ^fg(#FFFFFF) ^fg(#FF1778)%.2f%  ^fg(#FF1778)^bg(#C5C1AA)   ",
				  "  ^fg(#657b82)^bg(#FFB917)    ^fg(#FFFFFF) ^fg(#FFB917)%.2f%  ^fg(#FFB917)^bg(#C5C1AA)   ",
				  "  ^fg(#657b82)^bg(#228b22)    ^fg(#FFFFFF) ^fg(#0FFFF0)%.2f%  ^fg(#228b22)^bg(#C5C1AA)    "}; /*Battery Formats*/
static const float batterythres[2] = {25.,50.}; /*Battery Thresholds (percentage)*/
#endif

/*Separators*/
static const char *separators[] ={"","",""}; /* Left,Central and Right separators*/
 
/*Don't touch this!*/
enum PrintOrder {
  Plsep,
  Pcsep,
  Prsep,
  Pcpuload,
  Pmem,
  Pnetwork,
#ifdef ALSA
  Pvolume,
#endif
#ifdef BATTERY
  Pbattery,
#endif
  Ptime,
  Ptemperatures
};

/*Here the print order is set*/
static const enum PrintOrder porder[] ={Pcpuload,Pmem,Pnetwork, Pvolume, Pbattery, Ptime, Ptemperatures};
