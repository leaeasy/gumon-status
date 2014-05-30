/*Options*/

#define ALSA /*If defined it monitors a mixer status and volume*/
#define TIMER 1 /*Update the data every TIMER seconds*/
#define BATTERY

#define BATTERY_TIMER 100 /*Update the Battery data every BATTERY_TIMER seconds*/

/*CPUs*/
static const char *cpus_load[] = {"cpu"}; /*cpus in /proc/cpustats to monitor*/
static const char *cpusf_load[][3] = { {"| ^fg(#00FFFF) ^fg(#0FFF00)%.0f \% | ",           
				   "| ^fg(#00FFFF) ^bg(#FFB917)^fg(#FFB917)%.0f \% | ",
				   "| ^fg(#00FFFF) ^bg(#FF1778)^fg(#FF1778)%.0f \%| "}}; /*CPUs format [Low,Norm,High]*/
static const float cpusthres_load[][2] = { {25.,75.} };

static const char *cpus_freq[] = {"0","1"};
static const char * cpusf_freq[][3] =  { {"^fg(#0FFF00)%.0f% | ",           
					  " ^bg(#FFB917)^fg(#FFB917)%%.0f | ",
					  " ^bg(#FF1778)^fg(#FF1778)%%.0f | "},
					 {"^fg(#0FFF00)%.0f% | ",           
					  " ^bg(#FFB917)^fg(#FFB917)%%.0f | ",
					  " ^bg(#FF1778)^fg(#FF1778)%%.0f | "} };

static const float cpusthres_freq[][2] = { {1000.,1600.},
					   {1000.,1600.}};

/*MEM&SWAP*/
static const char memf[] = "^fg(#00FFFF) ^fg(#0FFF00)%.1f  %.0lfMB | "; /*Memory format*/

/*Network*/
static const char *netIFS[] = {"wlp6s0","enp8s0"}; /*Network IFs to monitor, will be shown only if connected*/

static const char *netIFSfdown[][3] = { {"^fg(#00FFFF) ^fg(#0FFF00)%.1fKB ",
					 "^fg(#00FFFF) ^bg(#FFB917)^fg(#FFB917)%.1fKB ",
					 "^fg(#00FFFF) ^bg(#FF1778)^fg(#FF1778)%.1fKB "}, 
			  	        {"^fg(#00FFFF) ^fg(#0FFF00)%.1fKB\% ",
					 "^fg(#00FFFF) ^bg(#FFB917)^fg(#FFB917)%.1fKB ",
					 "^fg(#00FFFF) ^bg(#FF1778)^fg(#FF1778)%.1fKB "} }; /*Download speed KB/s formats*/
static const float netIFSdthres[][2] = { {300.,600.}, /*Network IFs download thresholds in KB/s*/
					 {300.,600.} };

static const char *netIFSfup[][3] = { {"^fg(#0FFF00)%.1fKB% | ",
				       "^bg(#FFB917)^fg(#FFB917)%.1fKB% | ",
				       "^bg(#FF1778)^fg(#FF1778)%.1fKB% | "}, /*Upload speed in KB/s formats*/
				      {"^fg(#0FFF00)%.1fKB% | ",
				       "^bg(#FFB917)^fg(#FFB917)%.1fKB% | ",
				       "^bg(#FF1778)^fg(#FF1778)%.1fKB% | "} };

static const float netIFSuthres[][2] = { {300.,600.}, /*Network IFs upload thresholds in KB/s*/
					 {300.,600.} };

static const char WSSf[] = {"^fg(#00FFFF) ^fg(#0FFF00)%.2f% | "};/*If the Net IF is wireless, the signal strenght 
							   is printed along, this is the format of the 
							   signal strenght >=0.00 <=1.00*/ 

/*Time*/
static const char timef[] = "| ^fg(#FF1778) %a %d/%m/%y | ^fg(#FF1778) %H:%M:%S | ";/*Time format, see man strftime*/

/*Temperature reading*/
static const char *temperatures[] = {"temp2_input","temp3_input"}; /*files in /sys/devices/platform/coretemp.0/ to monitor*/
static const char *temperaturesf[][3] = { {"| ^fg(#00FFFF) ^fg(#0FFF00)%.0f°% ",
					   "| ^fg(#00FFFF) ^bg(#FFB917)^fg(#FFB917)%.0f° ",
					   "| ^fg(#00FFFF) ^bg(#FF1778)^fg(#FF1778)%.0f° "},
					  {"^fg(#0FFF00)%.0f°% | ",
					   "^bg(#FFB917)^fg(#FFB917)%.0f° | ",
					   "^bg(#FF1778)^fg(#FF1778)%.0f° | "} }; /*Temps format*/

static const float temperaturesthres[][2] = { {60.,90.}, /*Temps thresholds in degrees celsius*/
					      {60.,90.} };

#ifdef ALSA
/*Audio*/
const static char soundcard[] =  "default"; /*Soundcard to monitor*/
const static char mixername[] =  "Master"; /*Mixer to monitor*/
const static char *volumestatus[] = {"| ^fg(#FF1778) -","| ^fg(#00FFFF) *"}; /*Volume status 1.Mute 2.Normal*/
const static char volumef[] = "%s ^fg(#0FFF00)%.0f% | ";/*Volume format (status and volume level in % */
#endif


#ifdef BATTERY
/*BATTERY*/
static const char battery[] = "BAT1"; /*folder in /sys/class/power_supply */
static const char *batteryf[3] = {"^fg(#00FFFD) ^bg(#FF1778)^fg(#FF1778) %.2f | ",
				  "^fg(#00FFFE) ^bg(#FFB917)^fg(#FFB917) %.2f | ",
				  "^fg(#00FFFG) ^fg(#0FFF00)%.2f% |"}; /*Battery Formats*/
static const float batterythres[2] = {25.,50.}; /*Battery Thresholds (percentage)*/
#endif

/*Separators*/
static const char *separators[] ={"<","|",">"}; /* Left,Central and Right separators*/
 
/*Don't touch this!*/
enum PrintOrder {
  Plsep,
  Pcsep,
  Prsep,
  Pcpuload,
  Pcpufreq,
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
static const enum PrintOrder porder[] ={Pcpuload,Pmem,Pnetwork,Pcsep,Pvolume,Prsep,Ptime,Pbattery};
