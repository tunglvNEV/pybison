













#define		APLOG_DIR		"/it/log/"
#define		MAIL_FILENM_LEN	255

#define		MAX_MAIL_LINE	200
#define		MAX_CMD_PARAM	20

#define		LOCK_FILENAME	"/it/lock/ml_ent%s.lck"

#define		MAIL_SETDIR		"/it/%s/set_mail/"
#define		MAIL_WORKDIR	"/it/%s/work_mail/"

#define		CHR_PHONE_PREFIX	'k'
#define		CHR_PHONE_POSTFIX	'@'

#define		DATA_ARRAY_MAX	50		
#define		DIR_NAME_MAX	1024	
#define		CMD_LEN_MAX		1024	
#define		PAUSE_TIMES_MAX	10		


#define		MAIL_ADDR_MAX_LEN	128
#define		SUBJECT_MAX_LEN		256
#define		SR_TYP_MAX_LEN		1
#define		EVENTCD_MAX_LEN		3
#define		MESSAGEID_MAX_LEN	1000
#define		BODY_MAX_LEN		2000
#define		HEADER_MAX_LEN		2000
#define		MESSAGE_ID_LEN		256

#define		CHR_ML_ADDR_PREFIX		'<'	
#define		CHR_ML_ADDR_POSTFIX		'>'	

#define		GPS_ERROR_LATITUDE	"XXX.XXXX"
#define		GPS_ERROR_LONGITUDE	"XXXX.XXXX"

#define		MAIL_TKN_HEADER_FROM				"From: "
#define		MAIL_TKN_HEADER_TO					"To: "
#define		MAIL_TKN_MESSAGE_ID					"Message-Id: "
#define		MAIL_TKN_BODY_TO					"To: "
#define		MAIL_TKN_NG_USER_UNKNOWN			"User unknown"
#define		MAIL_TKN_NG_NC_STATUS_NG			"NC status NG"




#define		DBCON_1			"FOR_LOCK"






typedef struct {
	int		mtype;					
	char	mtext[4];				
} MSGBUF;


typedef struct	{
	int		mail_msg_ky;			
	char	oracle_connect_string[256];
	char	snd_ml_shell[DIR_NAME_MAX];
	char	from_address[256];		
	char	reply_address[256];		
	char	mail_work_dir[1024 + 1];
	char	mail_set_dir[1024 + 1];	
	char	lock_file_name[1024 + 1];
	char	time_log_str[4+1];		
	char	time_log_stp[4+1];		
	char	pause_str_times[4+1][PAUSE_TIMES_MAX];
	char	pause_stp_times[4+1][PAUSE_TIMES_MAX];
} ENVDATA;

#define		BODY_LINE_MAX_LEN	1000		
#define		EQUIP_NO_MAX_LEN	20			
#define		CUST_EQUIP_NO_MAX_LEN	25		
#define		TIME_MAX_LEN		20			
#define		PROC_NAME_MAX_LEN	9			
#define		MAIL_TYP_MAX_LEN	3			
#define		LATITUDE_MAX_LEN	10			
#define		LONGITUDE_MAX_LEN	10			
#define		TEL_NO_MAX_LEN		20			
#define		CUST_TEL_NO_MAX_LEN	20			
#define		IP_ADDRESS_MAX_LEN	15			
#define		ORA_ERR_MSG_MAX_LEN	1024		
#define		ERR_MSG_MAX_LEN		1024		
#define		CUST_NM				60			
#define		SHOP_CD_MAX_LEN		6			
#define		EQUIP_SERIAL_NO_MAX_LEN	18		
#define		EQUIP_NM_MAX_LEN	20			
#define		GROUP_CD_MAX_LEN	10			
#define		EGN_STA_MAX_LEN		6			
#define		MAIL_CONT_MAX_LEN	40			
#define		MAIL_STATUS_MAX_LEN	8			
#define		SERIAL_NO_MAX_LEN	40			
#define		CMD_MAX_LEN			2			
#define		YYMMDDHHMI_MAX_LEN	10			
#define		DATA_CD_MAX_LEN		2			
#define		DIAGNOSIS_DATA_MAX_LEN	36		
#define		DIAGNOSIS_NO_MAX_LEN	14		
#define		MC_PNO_MAX_LEN		15			
#define		MC_VER_MAX_LEN		5			
#define		RAIREKI_MAX_LEN		2			
#define		HOUR_METER_MAX_LEN	6			
#define		ENGINE_ON_OF_MAX_COUNT	100		
#define		SERVICE_DIAG_MAX_COUNT	50		
#define		ALARM_INQUIRY_MAX_COUNT	50		
#define		MC_PNO_MAX_LEN	15				
#define		MC_VER_MAX_LEN	5				
#define		ITC_VERSION		10				
#define		ERROR_CD_LEN	20				
#define		ALARM_CD_MAX_LEN	2			

#define		MAX_HOZEN_PARAM		50
#define		MAX_HANYO_PARAM		20			
#define		CONST_C20			20
#define		CONST_C30			30
#define		CONST_C200			200

#define		MAX_HANYO_REC		1 + 20		
#define		CONST_HANYO_KEY		20			
#define		CONST_HANYO_DATA	250			
#define		MAX_FDFR_REC		20			
#define		CONST_FDFR_DATA		50			

#define		MAX_AE_REC			100		
#define		MAX_AR_REC			26		
#define		MAX_RR_REC			3		
#define		MAX_KL_REC			45		



#define		MTYP_BATCH_DAYTIME		"BATCH_D"
#define		MTYP_BATCH_NIGHT_OPE	"BATCH_N1"
#define		MTYP_BATCH_NIGHT_NOPE	"BATCH_N2"
#define		MTYP_BATCH_NIGHT_EXP	"BATCH_N3"
#define		MTYP_SC					"SC"	
#define		MTYP_SA					"SA"	
#define		MTYP_BT					"BT"	
#define		MTYP_RT					"RT"	
#define		MTYP_AM					"AM"	
#define		MTYP_CL					"CL"	
#define		MTYP_CM0				"CM0"	
#define		MTYP_CM1				"CM1"	
#define		MTYP_CT0				"CT0"	
#define		MTYP_CT1				"CT1"	
#define		MTYP_HS					"HS"	
#define		MTYP_HE					"HE"	
#define		MTYP_HF					"HF"	
#define		MTYP_HH					"HH"	
#define		MTYP_HL					"HL"	
#define		MTYP_NG					"NG_MAIL"
#define		MTYP_AH					"AH"	
#define		MTYP_SD					"SD"	
#define		MTYP_RM					"RM"	
#define		MTYP_XX					"XX"	
#define		MTYP_XX_V7				"XX_V7"	
#define		MTYP_ONLY_POS			"ONLY_POS"
#define		MTYP_TD					"TD"	
#define		MTYP_BATCH_OPE			"BATCH1"
#define		MTYP_BATCH_NOPE			"BATCH2"
#define		MTYP_SS					"SS"	
#define		MTYP_SR					"SR"	
#define		MTYP_SG					"SG"	
#define		MTYP_SU					"SU"	
#define		MTYP_HD					"HD"	
#define		MTYP_HQ					"HQ"	
#define		MTYP_HP					"HP"	
#define		MTYP_DG					"DG"	
#define		MTYP_HANYO				"HANYO"	
#define		MTYP_FDFR				"FDFR"	
#define		MTYP_HDHQHP				"HDHQHP"
#define		MTYP_LKOK				"LKOK"	
#define		MTYP_AE					"AE"	
#define		MTYP_AR					"AR"	
#define		MTYP_RR					"RR"	
#define		MTYP_SSID				"SSID"	
#define		MTYP_KL					"KL"	

#define		MTYP_XXXX				"XXXX"	











typedef struct	{
	char	sysdate[TIME_MAX_LEN + 1];		
	char	proc[PROC_NAME_MAX_LEN + 1];	
	char	exec_proc[20 + 1];				
} PROC_COM_PARAM;


typedef struct	{
	char	equip_no[EQUIP_NO_MAX_LEN + 1];	
	int		seq;							
	char	mail_date[TIME_MAX_LEN + 1];	
	char	err_msg[ERR_MSG_MAX_LEN + ORA_ERR_MSG_MAX_LEN + 1];
	int		mail_type_flg;					
	int		mail_ng_flg;					
	char	mail_type[10 + 1];				
	char	mail_type_forlog[MAIL_TYP_MAX_LEN + 1];
	char	mail_file_nm[MAIL_FILENM_LEN + 1];
	char	from_mailaddr[MAIL_ADDR_MAX_LEN + 1];
	char	to_mailaddr[MAIL_ADDR_MAX_LEN + 1];
	char	tel_no[TEL_NO_MAX_LEN + 1];		
	char	itc_serial_no[SERIAL_NO_MAX_LEN + 1];
	char	itc_version[ITC_VERSION + 1];		
	int		keiho_stop;						
} CMD_COM_PARAM;



typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	latitude[LATITUDE_MAX_LEN+1];	
	char	longitude[LONGITUDE_MAX_LEN+1];	
	char	hh24middmm[TIME_MAX_LEN + 1];	
	int		chuuki;							
} CMD_POS_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		power_on_h;						
} CMD_H_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		area_flg;						
} CMD_A_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		
	char	engine_state_flg[EGN_STA_MAX_LEN + 1];
} CMD_EG_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	hh24mi[TIME_MAX_LEN + 1];		
	char	am_r_status[MAIL_STATUS_MAX_LEN+1];
} CMD_AMOF_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	hh24mi[TIME_MAX_LEN + 1];		
	char	am_r_status[MAIL_STATUS_MAX_LEN+1];
} CMD_AMON_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	hold_al[TIME_MAX_LEN + 1];		
	char	am_r_status[MAIL_STATUS_MAX_LEN+1];
} CMD_AM_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	latitude1[LATITUDE_MAX_LEN+1];	
	char	longitude1[LONGITUDE_MAX_LEN+1];
	char	latitude2[LATITUDE_MAX_LEN+1];	
	char	longitude2[LONGITUDE_MAX_LEN+1];
	char	cl_r_status[MAIL_STATUS_MAX_LEN+1];
} CMD_CL_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	yymmddhh24mi[TIME_MAX_LEN + 1];	
} CMD_SC_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	cm0_r_status[MAIL_STATUS_MAX_LEN+1];
} CMD_CM0_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	cm1_r_status[MAIL_STATUS_MAX_LEN+1];
} CMD_CM1_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	ct0_tel_no[TEL_NO_MAX_LEN + 1];	
} CMD_D0_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];			
	char	ct0_ip_address[IP_ADDRESS_MAX_LEN + 1];	
} CMD_D1_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	ct0_sei_y[TIME_MAX_LEN + 1];	
} CMD_D2_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		ct0_mechatro;					
} CMD_D3_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		ct1_receive_byte;				
} CMD_M0_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		ct1_send_byte;					
} CMD_M1_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		ct1_receive_mail;				
} CMD_M2_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		ct1_send_mail;					
} CMD_M3_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		ct1_retry;						
} CMD_M4_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		ct1_reserve1;					
} CMD_M5_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		ct1_reserve2;					
} CMD_M6_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		ct1_reserve3;					
} CMD_M7_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		ct1_reserve4;					
} CMD_M8_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		abnormal_flg;					
} CMD_SA_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		abnormal_flg;					
} CMD_BT_PARAM;


typedef struct STRCT_CMD_T_PARAM	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	yymmddhh24mi[TIME_MAX_LEN + 1];	
	struct STRCT_CMD_T_PARAM *parent;
	struct STRCT_CMD_T_PARAM *next;
} CMD_T_PARAM;


typedef struct STRCT_CMD_P_PARAM	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	yymmddhh24mi[TIME_MAX_LEN + 1];	
	struct STRCT_CMD_P_PARAM *parent;
	struct STRCT_CMD_P_PARAM *next;
} CMD_P_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		idle_h;							
} CMD_I_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		running_h;						
} CMD_R_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		high_r_h;						
} CMD_C_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		nb_h;							
} CMD_N_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		fuel_per;						
} CMD_F_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		e_temp_1;						
	int		e_temp_2;						
	int		e_temp_3;						
	int		e_temp_4;						
} CMD_W_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		pump_p1;						
	int		pump_p2;						
	int		pump_p3;						
	int		pump_p4;						
} CMD_U_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		ope_amount;						
} CMD_J_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		change_h;						
} CMD_EC_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		change_h;						
} CMD_FC_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		change_h;						
} CMD_HC_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		change_h;						
} CMD_LC_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		state_h;						
} CMD_OV_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		fuel_tmp;						
} CMD_FT_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		fuel_dt;						
} CMD_FS_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	group_cd[GROUP_CD_MAX_LEN+1];	
	char	sindan_no[DIAGNOSIS_NO_MAX_LEN+1];
} CMD_SD1_PARAM;


typedef struct STRCT_CMD_SD2_PARAM {
	char	cmd_all[BODY_LINE_MAX_LEN+1];			
	char	diagnoisi_data[DIAGNOSIS_DATA_MAX_LEN+1];
													
	struct  STRCT_CMD_SD2_PARAM *parent;
	struct  STRCT_CMD_SD2_PARAM *next;
} CMD_SD2_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	group_cd[GROUP_CD_MAX_LEN+1];	
	char	sd_status[MAIL_STATUS_MAX_LEN+1];
} CMD_SD3_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	hs_r_cont[MAIL_CONT_MAX_LEN+1];	
	char	reply[MAIL_STATUS_MAX_LEN+1];	
} CMD_HS_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	he_r_cont[MAIL_CONT_MAX_LEN+1];	
	char	reply[MAIL_STATUS_MAX_LEN+1];	
} CMD_HE_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	hf_r_cont[MAIL_CONT_MAX_LEN+1];	
	char	reply[MAIL_STATUS_MAX_LEN+1];	
} CMD_HF_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	hh_r_cont[MAIL_CONT_MAX_LEN+1];	
	char	reply[MAIL_STATUS_MAX_LEN+1];	
} CMD_HH_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	hl_r_cont[MAIL_CONT_MAX_LEN+1];	
	char	reply[MAIL_STATUS_MAX_LEN+1];	
} CMD_HL_PARAM;


typedef struct STRCT_CMD_AH_PARAM {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		tousi_no;						
	char	raireki1[BODY_LINE_MAX_LEN+1];	
	char	raireki2[RAIREKI_MAX_LEN+1];	
	char	raireki3[RAIREKI_MAX_LEN+1];	
	char	raireki4[RAIREKI_MAX_LEN+1];	
	char	raireki5[RAIREKI_MAX_LEN+1];	
	char	raireki6[RAIREKI_MAX_LEN+1];	
	char	raireki7[RAIREKI_MAX_LEN+1];	
	char	raireki8[RAIREKI_MAX_LEN+1];	
	char	raireki9[RAIREKI_MAX_LEN+1];	
	char	raireki10[RAIREKI_MAX_LEN+1];	
	char	raireki11[RAIREKI_MAX_LEN+1];	
	char	raireki12[RAIREKI_MAX_LEN+1];	
	char	raireki13[RAIREKI_MAX_LEN+1];	
	char	raireki14[RAIREKI_MAX_LEN+1];	
	int		hour_meter;						
	struct STRCT_CMD_AH_PARAM *parent;
	struct STRCT_CMD_AH_PARAM *next;
} CMD_AH_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];
	char	mc_pno[MC_PNO_MAX_LEN+1];	
} CMD_PN_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];
	char	mc_ver[MC_VER_MAX_LEN+1];	
} CMD_VR_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	alarm_cd[CMD_MAX_LEN+1];		
	char	error_cd[ERROR_CD_LEN+1];		
	int		alarm_status;					
	char	yymmddhh24mi[YYMMDDHHMI_MAX_LEN+1];
	char	eg_status[2];					
} CMD_XX_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int	fuel_cons_amount;					
	int	power_on_h;							
} CMD_NP_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		fuel_cons_h_mode;				
	int		fuel_cons_s_mode;				
	int		fuel_cons_e_mode;				
} CMD_MC_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		fuel_pon_h_mode;	
	int		fuel_pon_s_mode;	
	int		fuel_pon_e_mode;	
} CMD_MT_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		turning_h;						
} CMD_SW_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		adjust;							
} CMD_ADJUST_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		eg_st_count;					
} CMD_ST_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	dpf_level[10 + 1];				
} CMD_SL_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	td_value[5 + 1];				
	char	td_status[MAIL_STATUS_MAX_LEN+1];
} CMD_TD_PARAM;


typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	char	ssid_status[2 + 1];				
	char	ssid_value[5 + 1];				
} CMD_SSID_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		count;							
	char	value00[CONST_C20+1];			
	char	value01[CONST_C20+1];			
	char	value02[CONST_C20+1];			
	char	value03[CONST_C20+1];			
	char	value04[CONST_C20+1];			
	char	value05[CONST_C20+1];			
	char	value06[CONST_C20+1];			
	char	value07[CONST_C20+1];			
	char	value08[CONST_C20+1];			
	char	value09[CONST_C20+1];			
	char	value10[CONST_C20+1];			
	char	value11[CONST_C20+1];			
	char	value12[CONST_C20+1];			
	char	value13[CONST_C20+1];			
	char	value14[CONST_C20+1];			
	char	value15[CONST_C20+1];			
	char	value16[CONST_C20+1];			
	char	value17[CONST_C20+1];			
	char	value18[CONST_C20+1];			
	char	value19[CONST_C20+1];			
	char	value20[CONST_C20+1];			
	char	value21[CONST_C20+1];			
	char	value22[CONST_C20+1];			
	char	value23[CONST_C20+1];			
	char	value24[CONST_C20+1];			
	char	value25[CONST_C20+1];			
	char	value26[CONST_C20+1];			
} CMD_C20X5_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		count;							
	char	value00[CONST_C30+1];			
	char	value01[CONST_C30+1];			
	char	value02[CONST_C30+1];			
	char	value03[CONST_C30+1];			
	char	value04[CONST_C30+1];			
	char	value05[CONST_C30+1];			
	char	value06[CONST_C30+1];			
	char	value07[CONST_C30+1];			
	char	value08[CONST_C30+1];			
	char	value09[CONST_C30+1];			
	char	value10[CONST_C30+1];			
} CMD_C30X10_PARAM;



typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		count;							
	char	value00[CONST_C30+1];			
	char	value01[CONST_C30+1];			
} CMD_C30X1_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		count;							
	char	value00[CONST_C30+1];			
	char	value01[CONST_C30+1];			
	char	value02[CONST_C30+1];			
	char	value03[CONST_C30+1];			
	char	value04[CONST_C30+1];			
	char	value05[CONST_C30+1];			
} CMD_C30X5_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		count;							
	char	key1[CONST_HANYO_KEY+1];		
	char	key2[CONST_HANYO_KEY+1];		
	char	key3[CONST_HANYO_KEY+1];		
	char	key4[CONST_HANYO_KEY+1];		
	char	key5[CONST_HANYO_KEY+1];		
	char	reckey1[CONST_HANYO_KEY+1];		
	char	value01[CONST_HANYO_DATA+1];	
} CMD_HANYO_PARAM;



typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		count;							
	int		value_count;					
	char	value00[CONST_C20+1];			
	char	value01[CONST_C20+1];			
	char	value02[CONST_C20+1];			
	char	value03[CONST_C20+1];			
	char	value04[CONST_C20+1];			
	char	value05[CONST_C20+1];			
	char	value06[CONST_C20+1];			
	char	value07[CONST_C20+1];			
	char	value08[CONST_C20+1];			
	char	value09[CONST_C20+1];			
	char	value10[CONST_C20+1];			
	char	value11[CONST_C20+1];			
	char	value12[CONST_C20+1];			
	char	value13[CONST_C20+1];			
	char	value14[CONST_C20+1];			
	char	value15[CONST_C20+1];			
	char	value16[CONST_C20+1];			
	char	value17[CONST_C20+1];			
	char	value18[CONST_C20+1];			
	char	value19[CONST_C20+1];			
	char	value20[CONST_C20+1];			
	char	value21[CONST_C20+1];			
	char	value22[CONST_C20+1];			
	char	value23[CONST_C20+1];			
	char	value24[CONST_C20+1];			
	char	value25[CONST_C20+1];			
	char	value26[CONST_C20+1];			
	char	value27[CONST_C20+1];			
	char	value28[CONST_C20+1];			
	char	value29[CONST_C20+1];			
	char	value30[CONST_C20+1];			
	char	value31[CONST_C20+1];			
	char	value32[CONST_C20+1];			
	char	value33[CONST_C20+1];			
	char	value34[CONST_C20+1];			
	char	value35[CONST_C20+1];			
	char	value36[CONST_C20+1];			
	char	value37[CONST_C20+1];			
	char	value38[CONST_C20+1];			
	char	value39[CONST_C20+1];			
	char	value40[CONST_C20+1];			
	char	value41[CONST_C20+1];			
	char	value42[CONST_C20+1];			
	char	value43[CONST_C20+1];			
	char	value44[CONST_C20+1];			
	char	value45[CONST_C20+1];			
	char	value46[CONST_C20+1];			
	char	value47[CONST_C20+1];			
	char	value48[CONST_C20+1];			
	char	value49[CONST_C20+1];			
	char	value50[CONST_C20+1];			
} CMD_HANYO06_PARAM;


typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	
	int		count;							
	char	value00[CONST_C200+1];			
	char	value01[CONST_C200+1];			
	char	value02[CONST_C200+1];			
	char	value03[CONST_C200+1];			
	char	value04[CONST_C200+1];			
	char	value05[CONST_C200+1];			
} CMD_C200X5_PARAM;



typedef struct	{
	char	header[HEADER_MAX_LEN + 1];				
	char	body[BODY_MAX_LEN + 1];					
	char	from_mailaddr[MAIL_ADDR_MAX_LEN + 1];	
	char	to_mailaddr[MAIL_ADDR_MAX_LEN + 1];		
	char	body_to_mailaddr[MAIL_ADDR_MAX_LEN + 1];
	int		nc_status_ng;							
	int		no_mailbox;								
	char	sr_typ[1+1];							
	char	mail_typ[MAIL_TYP_MAX_LEN+1];			
	int		s_flg;									
	char	message_id[MESSAGE_ID_LEN + 1];			
} MAIL_INFO;


typedef struct	{
	char	datfile[1024];
	char	equipno[20];
	char	mailaddr[128];
	int		seq;
	int		lineno;
} APLOG_INFO;




char AT_DBCON_1[10];




