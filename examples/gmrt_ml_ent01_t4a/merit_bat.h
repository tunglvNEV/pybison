/* ======================================================================== */
/*	�R�x���R���@�l�����p�@�ғ��@�Ǘ��V�X�e��				*/
/*	�t�@�C����	�F	merit_bat.h												*/
/*	����		�F	�o�b�`�n�����̋��ʃw�b�_�t�@�C��						*/
/* ------------------------------------------------------------------------ */
/*	�쐬	SKCS	2009.02.01												*/
/*	�X�V	SKCS	2009.07.21	���Ћ@�Ή�									*/
/*			KSC		2011.10.25	�~�j���p�F���O�^�I�[�u�R���Q�Ή�			*/
/* ======================================================================== */

/* ------------------------------------------------------------------------ */
/*	�萔�̒�`																*/
/* ------------------------------------------------------------------------ */

#define		APLOG_DIR		"/it/log/"	/*	�A�v�����O�i�[�f�B���N�g��		*/
#define		MAIL_FILENM_LEN	255	/*	��M�e�L�X�g(���[��)�t�@�C�����̒���	*/

#define		MAX_MAIL_LINE	200	/*	(����n/��s������)���[���s�ő勖�e��	*/
#define		MAX_CMD_PARAM	20	/*	(����n)�R�}���h�p�����[�^�ő勖�e��	*/

#define		LOCK_FILENAME	"/it/lock/ml_ent%s.lck"/*	LOCK�t�@�C����	*/

#define		MAIL_SETDIR		"/it/%s/set_mail/"	/*	���[���z�uDIR		*/
#define		MAIL_WORKDIR	"/it/%s/work_mail/"/*	���[�����DIR		*/

#define		CHR_PHONE_PREFIX	'k'	/* ���[���A�h���X�̓d�b�ԍ�	���O�̕���	*/
#define		CHR_PHONE_POSTFIX	'@'	/* 							����̕���	*/

#define		DATA_ARRAY_MAX	50			/*	�R�}���h�f�[�^�z��̍ő吔		*/
#define		DIR_NAME_MAX	1024		/*	�f�B���N�g�����ő咷			*/
#define		CMD_LEN_MAX		1024		/*	Unix�R�}���h����				*/
#define		PAUSE_TIMES_MAX	10			/*	���s�}�~���Ԑݒ�ő吔			*/

/*	���[���w�b�_�֘A														*/
#define		MAIL_ADDR_MAX_LEN	128
#define		SUBJECT_MAX_LEN		256
#define		SR_TYP_MAX_LEN		1
#define		EVENTCD_MAX_LEN		3
#define		MESSAGEID_MAX_LEN	1000
#define		BODY_MAX_LEN		2000
#define		HEADER_MAX_LEN		2000
#define		MESSAGE_ID_LEN		256

#define		CHR_ML_ADDR_PREFIX		'<'		/* ���[���A�h���X	���O�̕���	*/
#define		CHR_ML_ADDR_POSTFIX		'>'		/* ���[���A�h���X	����̕���	*/

#define		GPS_ERROR_LATITUDE	"XXX.XXXX"
#define		GPS_ERROR_LONGITUDE	"XXXX.XXXX"

#define		MAIL_TKN_HEADER_FROM				"From: "
#define		MAIL_TKN_HEADER_TO					"To: "
#define		MAIL_TKN_MESSAGE_ID					"Message-Id: "
#define		MAIL_TKN_BODY_TO					"To: "
#define		MAIL_TKN_NG_USER_UNKNOWN			"User unknown"
#define		MAIL_TKN_NG_NC_STATUS_NG			"NC status NG"

/*	���̑��萔																*/

/*	DB�ڑ�AT			*/
#define		DBCON_1			"FOR_LOCK"

/* ------------------------------------------------------------------------ */
/*	�^�̒�`																*/
/* ------------------------------------------------------------------------ */

/*	��M���b�Z�[�W�i�[�o�b�t�@�̍\����`									*/
typedef struct {
	int		mtype;						/*	���b�Z�[�W�^�C�v				*/
	char	mtext[4];					/*	���b�Z�[�W�e�L�X�g				*/
} MSGBUF;

/*	���ϐ����i�[��̒�`												*/
typedef struct	{
	int		mail_msg_ky;				/*	���b�Z�[�W�L���[�̃L�[			*/
	char	oracle_connect_string[256];	/*	Oracle�ڑ�������				*/
	char	snd_ml_shell[DIR_NAME_MAX];	/*	�x��ʒm���[�����M�p�V�F��		*/
	char	from_address[256];			/*	�x��ʒm���[�����M�A�h���X		*/
	char	reply_address[256];			/*	�x��ʒm���[�����M�A�h���X		*/
	char	mail_work_dir[1024 + 1];	/*	���[�����DIR					*/
	char	mail_set_dir[1024 + 1];		/*	���[���i�[DIR(ml_rcv�Ɠ��l)		*/
	char	lock_file_name[1024 + 1];	/*	���b�N�t�@�C����				*/
	char	time_log_str[4+1];			/*	�^�C�����O�o�͊J�n����			*/
	char	time_log_stp[4+1];			/*	�^�C�����O�o�͏I������			*/
	char	pause_str_times[4+1][PAUSE_TIMES_MAX];	/*	���s�}�~�J�n����	*/
	char	pause_stp_times[4+1][PAUSE_TIMES_MAX];	/*	���s�}�~�I������	*/
} ENVDATA;

#define		BODY_LINE_MAX_LEN	1000			/*	�R�}���h�s�S���̍ő吔	*/
#define		EQUIP_NO_MAX_LEN	20				/*	�ݔ��ԍ��̍ő吔		*/
#define		CUST_EQUIP_NO_MAX_LEN	25			/*	�q��Ǘ��ԍ��̍ő吔	*/
#define		TIME_MAX_LEN		20				/*	�������ڂ̍ő吔		*/
#define		PROC_NAME_MAX_LEN	9				/*	�v���Z�X���̍ő吔		*/
#define		MAIL_TYP_MAX_LEN	3				/*	���[���^�C�v�̍ő吔	*/
#define		LATITUDE_MAX_LEN	10				/*	�ܓx�̍ő吔			*/
#define		LONGITUDE_MAX_LEN	10				/*	�o�x�̍ő吔			*/
#define		TEL_NO_MAX_LEN		20				/*	�d�b�ԍ��̍ő吔		*/
#define		CUST_TEL_NO_MAX_LEN	20				/*	(�ڋq)�d�b�ԍ��̍ő吔	*/
#define		IP_ADDRESS_MAX_LEN	15				/*	IP�A�h���X�̍ő吔		*/
#define		ORA_ERR_MSG_MAX_LEN	1024			/*	Oracle���b�Z�[�W�p�ő吔*/
#define		ERR_MSG_MAX_LEN		1024			/*	�G���[���b�Z�[�W�̍ő吔*/
#define		CUST_NM				60				/*	�ڋq���̍ő咷			*/
#define		SHOP_CD_MAX_LEN		6				/*	�c�Ə��R�[�h�̍ő咷	*/
#define		EQUIP_SERIAL_NO_MAX_LEN	18			/*	�ݔ��V���A���ԍ��̍ő咷*/
#define		EQUIP_NM_MAX_LEN	20				/*	�ݔ��e�L�X�g�̍ő咷	*/
#define		GROUP_CD_MAX_LEN	10				/*	�O���[�v�R�[�h�̍ő咷	*/
#define		EGN_STA_MAX_LEN		6				/*	�G���W����Ԃ̍ő咷	*/
#define		MAIL_CONT_MAX_LEN	40				/*	���[�����e�̍ő�l		*/
#define		MAIL_STATUS_MAX_LEN	8				/*	���[����Ԃ̍ő�l		*/
#define		SERIAL_NO_MAX_LEN	40				/*	ITC�V���A��NO�̍ő吔	*/
#define		CMD_MAX_LEN			2				/*	�R�}���h�̍ő吔		*/
#define		YYMMDDHHMI_MAX_LEN	10				/*	�N�������̍ő吔		*/
#define		DATA_CD_MAX_LEN		2				/*	�f�[�^�R�[�h�̍ő咷	*/
#define		DIAGNOSIS_DATA_MAX_LEN	36			/*	�T�[�r�X�f�f���̍ő咷*/
#define		DIAGNOSIS_NO_MAX_LEN	14			/*	�f�f�Ǘ�No�̍ő咷		*/
#define		MC_PNO_MAX_LEN		15				/*	���J�g���R���g���[���p�[�cNo�̍ő咷	*/
#define		MC_VER_MAX_LEN		5				/*	���J�g���R���g���[���p�[�cVer�̍ő咷	*/
#define		RAIREKI_MAX_LEN		2				/*	�̏ᗈ���̍ő咷	*/
#define		HOUR_METER_MAX_LEN	6				/*	�A�����[�^�̍ő咷	*/
#define		ENGINE_ON_OF_MAX_COUNT	100			/*	�G���W��ON/OF�J��Ԃ���(�K��ł�50�Z�b�g����51�Z�b�g�����������ߊg��(2011.12))	*/
#define		SERVICE_DIAG_MAX_COUNT	50			/*	�T�[�r�X�f�f���J��Ԃ���(���ɋK��Ȃ�?)	*/
#define		ALARM_INQUIRY_MAX_COUNT	50			/*	�̏ᗈ���J��Ԃ���(���ɋK��Ȃ�?)	*/
#define		MC_PNO_MAX_LEN	15					/*	Ҷ�ۺ��۰��߰�NO�̍ő吔	*/
#define		MC_VER_MAX_LEN	5					/*	Ҷ�ۺ��۰׿��ver�̍ő吔	*/
#define		ITC_VERSION		10					/*	ITC�o�[�W�����̌���			*/
#define		ERROR_CD_LEN	20					/*	[Tier4A]���Ȑf�f�G���[�R�[�h*/
#define		ALARM_CD_MAX_LEN	2				/*	�x��R�[�h					*/

#define		MAX_HOZEN_PARAM		50
#define		MAX_HANYO_PARAM		20				/*	�ғ����тւ̊g����񃌃R�[�h��	*/
#define		CONST_C20			20
#define		CONST_C30			30
#define		CONST_C200			200

#define		MAX_HANYO_REC		1 + 20			/*	�ėp�w�b�_�s�{�ėp�f�[�^�s	*/
#define		CONST_HANYO_KEY		20				/*	�ėpKEY���T�C�Y			*/
#define		CONST_HANYO_DATA	250				/*	�ėp	*/
#define		MAX_FDFR_REC		20				/*	�̏�f�f(���e�s��)	*/
#define		CONST_FDFR_DATA		50				/*	�̏�f�f�̒l�̃o�C�g��	*/

#define		MAX_AE_REC			100			/*	�Փˌy���@�\�؂�ւ����(�ő�P�O�O�s)	*/
#define		MAX_AR_REC			26			/*	�Փˌy�����|�[�g�iAR0�`AR25��26�s�j	*/
#define		MAX_RR_REC			3			/*	�Đ��f�f�iRR0�`RR2��3�s�j	*/
#define		MAX_KL_REC			45			/*	K-LOAD��ƃf�[�^(�ő�45�s)	*/


/*	���[���^�C�v(�����p)�萔													*/
#define		MTYP_BATCH_DAYTIME		"BATCH_D"	/*	���o�b�`					*/
#define		MTYP_BATCH_NIGHT_OPE	"BATCH_N1"	/*	��ԃo�b�`(�ғ�)			*/
#define		MTYP_BATCH_NIGHT_NOPE	"BATCH_N2"	/*	��ԃo�b�`(��ғ�)			*/
#define		MTYP_BATCH_NIGHT_EXP	"BATCH_N3"	/*	��ԃo�b�`(��O)			*/
#define		MTYP_SC					"SC"		/*	�N���x���`(SC)			*/
#define		MTYP_SA					"SA"		/*	�G���A�O�x���`(SA)		*/
#define		MTYP_BT					"BT"		/*	�o�b�e���[�͂����x���`(BT)*/
#define		MTYP_RT					"RT"		/*	�@�B��Ԗ₢���킹(RT����)	*/
#define		MTYP_AM					"AM"		/*	�N���x��L�����Ԑݒ�(AM����)*/
#define		MTYP_CL					"CL"		/*	�G���A�ݒ�(CL����)			*/
#define		MTYP_CM0				"CM0"		/*	�ʐM��~�ݒ�(CM0����)		*/
#define		MTYP_CM1				"CM1"		/*	�ʐM�ĊJ�ݒ�(CM1����)		*/
#define		MTYP_CT0				"CT0"		/*	�ʐM�e�X�g(CT0����)			*/
#define		MTYP_CT1				"CT1"		/*	�ʐM�ʊm�F(CT1����)			*/
#define		MTYP_HS					"HS"		/*	�A�����[�^�ύX(HS����)		*/
#define		MTYP_HE					"HE"		/*	�ݼ�ݵ�ٌ����c���ԕύX(HE����) */
#define		MTYP_HF					"HF"		/*	�R��̨�������c���ԕύX(HF����) */
#define		MTYP_HH					"HH"		/*	��Ɩ�̨�������c���ԕύX(HH����) */
#define		MTYP_HL					"HL"		/*	��Ɩ������c���ԕύX(HL����) */
#define		MTYP_NG					"NG_MAIL"	/*	NG���[��					*/
#define		MTYP_AH					"AH"		/*	�̏ᗈ��					*/
#define		MTYP_SD					"SD"		/*	�T�[�r�X�f�f				*/
#define		MTYP_RM					"RM"		/*	���J�g�����擾����(V7)	*/
#define		MTYP_XX					"XX"		/*	���Ȑf�f					*/
#define		MTYP_XX_V7				"XX_V7"		/*	���Ȑf�f(V7)				*/
#define		MTYP_ONLY_POS			"ONLY_POS"	/*	�ʒu���̂�				*/
#define		MTYP_TD					"TD"		/*	�����ݒ�(TD����)			*/
#define		MTYP_BATCH_OPE			"BATCH1"	/*	�P�O�^�o�b�`�i�ғ��j		*/
#define		MTYP_BATCH_NOPE			"BATCH2"	/*	�P�O�^�o�b�`�i��ғ��j		*/
#define		MTYP_SS					"SS"		/*	SIM�J�[�h�����x��			*/
#define		MTYP_SR					"SR"		/*	�ʐM�A���e�i�ؒf�x��		*/
#define		MTYP_SG					"SG"		/*	GPS�A���e�i�ؒf�x��			*/
#define		MTYP_SU					"SU"		/*	VCU�ʐM�s�\�x��				*/
#define		MTYP_HD					"HD"		/*	���N�f�f�w������			*/
#define		MTYP_HQ					"HQ"		/*	���N�f�f���{�ۑI������	*/
#define		MTYP_HP					"HP"		/*	���N�f�f����				*/
#define		MTYP_DG					"DG"		/*	���uDL����					*/
#define		MTYP_HANYO				"HANYO"		/*	�ėp���[���`��				*/
#define		MTYP_FDFR				"FDFR"		/*	�̏�f�f					*/
#define		MTYP_HDHQHP				"HDHQHP"	/*	���N�f�f					*/
#define		MTYP_LKOK				"LKOK"		/*	���u���b�N�ݒ艞��			*/
#define		MTYP_AE					"AE"		/*	�Փˌy���@�\�؊�			*/
#define		MTYP_AR					"AR"		/*	�Փˌy�����|�[�g			*/
#define		MTYP_RR					"RR"		/*	�Đ��f�f					*/
#define		MTYP_SSID				"SSID"		/*	SSID������					*/
#define		MTYP_KL					"KL"		/*	K-LOAD��ƃf�[�^			*/

#define		MTYP_XXXX				"XXXX"		/*	�z��O						*/


/*	�ݔ��֘A����(�ڋq���)�\����	*/
/*typedef struct	{*/
/*	char	equip_no[EQUIP_NO_MAX_LEN + 1];			/*	�ݔ��ԍ�			*/
/*	char	cust_equip_no[CUST_EQUIP_NO_MAX_LEN];	/*	�q��Ǘ��ԍ�		*/
/*	char	cust_nm[CUST_NM+1];						/*	�ڋq��				*/
/*	char	cust_tel_no[CUST_TEL_NO_MAX_LEN+1];		/*	�ڋq�d�b�ԍ�		*/
/*} EQUIP_INFO;*/

/*	�v���Z�X���ʍ\����	*/
typedef struct	{
	char	sysdate[TIME_MAX_LEN + 1];			/*	�V�X�e�����ʓ���		*/
	char	proc[PROC_NAME_MAX_LEN + 1];		/*	�v���Z�X��				*/
	char	exec_proc[20 + 1];					/*	���s�t�@�C����(���O�p)	*/
} PROC_COM_PARAM;

/*	���[�����ʍ\����														*/
typedef struct	{
	char	equip_no[EQUIP_NO_MAX_LEN + 1];		/*	�ݔ��ԍ�				*/
	int		seq;								/*	SEQ						*/
	char	mail_date[TIME_MAX_LEN + 1];		/*	�ʒu����(�N���������b)	*/
	char	err_msg[ERR_MSG_MAX_LEN + ORA_ERR_MSG_MAX_LEN + 1];	/*	�G���[MSG	*/
	int		mail_type_flg;						/*	���[�����(0:�ʏ�,1:�����e)	*/
	int		mail_ng_flg;						/*	NG���[���t���O(0:�ʏ�,1:NG)	*/
	char	mail_type[10 + 1];					/*	���[���^�C�v			*/
	char	mail_type_forlog[MAIL_TYP_MAX_LEN + 1];	/*	���[���^�C�v(���O�o�͗p)*/
	char	mail_file_nm[MAIL_FILENM_LEN + 1];	/*	��͒����[���t�@�C����	*/
	char	from_mailaddr[MAIL_ADDR_MAX_LEN + 1];	/*	���M�����[���A�h���X*/
	char	to_mailaddr[MAIL_ADDR_MAX_LEN + 1];	/*	���M�惁�[���A�h���X	*/
	char	tel_no[TEL_NO_MAX_LEN + 1];			/*	�d�b�ԍ�				*/
	char	itc_serial_no[SERIAL_NO_MAX_LEN + 1];	/*	ITC�V���A��NO		*/
	char	itc_version[ITC_VERSION + 1];			/*	ITC�o�[�W����		*/
	int		keiho_stop;							/* �x�񃁁[���ʒm�����}�~	*/
} CMD_COM_PARAM;


/*	�ʒu�R�}���h�\����														*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	latitude[LATITUDE_MAX_LEN+1];		/*	�ܓx					*/
	char	longitude[LONGITUDE_MAX_LEN+1];		/*	�o�x					*/
	char	hh24middmm[TIME_MAX_LEN + 1];		/*	��������				*/
	int		chuuki;								/*	���@���				*/
} CMD_POS_PARAM;

/*	�A�����[�^�R�}���h�\����												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		power_on_h;							/*	�ғ�����				*/
} CMD_H_PARAM;

/*	�G���A����R�}���h�\����												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		area_flg;							/*	�ر���O�׸�				*/
} CMD_A_PARAM;

/*	�G���W���ғ����R�}���h�\����											*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];			/*	�R�}���h�s�S��			*/
	char	engine_state_flg[EGN_STA_MAX_LEN + 1];	/*	�G���W������׸�		*/
} CMD_EG_PARAM;

/*	�N���x��L�����Ԑݒ�(AMOF)�R�}���h�\����								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	hh24mi[TIME_MAX_LEN + 1];			/*	����					*/
	char	am_r_status[MAIL_STATUS_MAX_LEN+1];	/*	����					*/
} CMD_AMOF_PARAM;

/*	�N���x��L�����Ԑݒ�(AMON)�R�}���h�\����								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	hh24mi[TIME_MAX_LEN + 1];			/*	����					*/
	char	am_r_status[MAIL_STATUS_MAX_LEN+1];	/*	����					*/
} CMD_AMON_PARAM;

/*	�N���x��L�����Ԑݒ�(AM)�R�}���h�\����									*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	hold_al[TIME_MAX_LEN + 1];			/*	�j�����L���w��			*/
	char	am_r_status[MAIL_STATUS_MAX_LEN+1];	/*	����					*/
} CMD_AM_PARAM;

/*	�G���A�ݒ�R�}���h�\����												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	latitude1[LATITUDE_MAX_LEN+1];		/*	�ܓx1					*/
	char	longitude1[LONGITUDE_MAX_LEN+1];	/*	�o�x1					*/
	char	latitude2[LATITUDE_MAX_LEN+1];		/*	�ܓx2					*/
	char	longitude2[LONGITUDE_MAX_LEN+1];	/*	�o�x2					*/
	char	cl_r_status[MAIL_STATUS_MAX_LEN+1];	/*	����					*/
} CMD_CL_PARAM;

/*	�N���x��R�}���h�\����													*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	yymmddhh24mi[TIME_MAX_LEN + 1];		/*	�N��������				*/
} CMD_SC_PARAM;

/*	�ʐM��~�����R�}���h�\����												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	cm0_r_status[MAIL_STATUS_MAX_LEN+1];	/*	�ʐM��~����			*/
} CMD_CM0_PARAM;

/*	�ʐM�ĊJ�����R�}���h�\����												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	cm1_r_status[MAIL_STATUS_MAX_LEN+1];	/*	�ʐM�ĊJ����			*/
} CMD_CM1_PARAM;

/*	�ʐM�e�X�g����(�d�b�ԍ�)�R�}���h�\����									*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	ct0_tel_no[TEL_NO_MAX_LEN + 1];		/*	�d�b�ԍ�				*/
} CMD_D0_PARAM;

/*	�ʐM�e�X�g����(IP�A�h���X)�R�}���h�\����								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];				/*	�R�}���h�s�S��	*/
	char	ct0_ip_address[IP_ADDRESS_MAX_LEN + 1];		/*	IP�A�h���X		*/
} CMD_D1_PARAM;

/*	�ʐM�e�X�g����(����)�R�}���h�\����										*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	ct0_sei_y[TIME_MAX_LEN + 1];		/*	������t				*/
} CMD_D2_PARAM;

/*	�ʐM�e�X�g����(���J�g���L��)�R�}���h�\����								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		ct0_mechatro;						/*	���J�g���L���׸�		*/
} CMD_D3_PARAM;

/*	�ʐM�m�F����(��M���[�����e��)�R�}���h�\����								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		ct1_receive_byte;					/*	��M���[���e��			*/
} CMD_M0_PARAM;

/*	�ʐM�m�F����(���M���[�����e��)�R�}���h�\����								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		ct1_send_byte;						/*	���M���[���e��			*/
} CMD_M1_PARAM;

/*	�ʐM�m�F����(��M���[����)�R�}���h�\����								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		ct1_receive_mail;					/*	��M���[����			*/
} CMD_M2_PARAM;

/*	�ʐM�m�F����(���M���[����)�R�}���h�\����								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		ct1_send_mail;						/*	���M���[����			*/
} CMD_M3_PARAM;

/*	�ʐM�m�F����(���g���C��)�R�}���h�\����								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		ct1_retry;							/*	���g���C��			*/
} CMD_M4_PARAM;

/*	�ʐM�ʊm�F����(�\���P)�R�}���h�\����							*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��	*/
	int		ct1_reserve1;						/*	�\���P			*/
} CMD_M5_PARAM;

/*	�ʐM�ʊm�F����(�\���Q)�R�}���h�\����							*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��	*/
	int		ct1_reserve2;						/*	�\���Q			*/
} CMD_M6_PARAM;

/*	�ʐM�ʊm�F����(�\���R)�R�}���h�\����							*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��	*/
	int		ct1_reserve3;						/*	�\���R			*/
} CMD_M7_PARAM;

/*	�ʐM�ʊm�F����(�\���S)�R�}���h�\����							*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��	*/
	int		ct1_reserve4;						/*	�\���S			*/
} CMD_M8_PARAM;

/*	�G���A�O�x��R�}���h�\����												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		abnormal_flg;						/*	�ُ�t���O(����/����)	*/
} CMD_SA_PARAM;

/*	�o�b�e���O���x��R�}���h�\����											*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		abnormal_flg;						/*	�ُ�t���O(����/����)	*/
} CMD_BT_PARAM;

/*	�G���W���n������											*/
typedef struct STRCT_CMD_T_PARAM	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	yymmddhh24mi[TIME_MAX_LEN + 1];		/*	�N��������				*/
	struct STRCT_CMD_T_PARAM *parent;
	struct STRCT_CMD_T_PARAM *next;
} CMD_T_PARAM;

/*	�G���W����~����											*/
typedef struct STRCT_CMD_P_PARAM	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	yymmddhh24mi[TIME_MAX_LEN + 1];		/*	�N��������				*/
	struct STRCT_CMD_P_PARAM *parent;
	struct STRCT_CMD_P_PARAM *next;
} CMD_P_PARAM;

/*	�����쎞��											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		idle_h;								/*	�����쎞��				*/
} CMD_I_PARAM;

/*	���s����											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		running_h;							/*	���s����				*/
} CMD_R_PARAM;

/*	�n�C���[�`�g�p����											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		high_r_h;							/*	�n�C���[�`�g�p����		*/
} CMD_C_PARAM;

/*	N&B�g�p����											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		nb_h;								/*	N&B�g�p����				*/
} CMD_N_PARAM;

/*	�R���c��											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	int		fuel_per;							/*	�R���c��				*/
} CMD_F_PARAM;

/*	�G���W���������z									*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		e_temp_1;							/*	����1				*/
	int		e_temp_2;							/*	����2				*/
	int		e_temp_3;							/*	����3				*/
	int		e_temp_4;							/*	����4				*/
} CMD_W_PARAM;

/*	�|���v���͕��z									*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		pump_p1;							/*	����1				*/
	int		pump_p2;							/*	����2				*/
	int		pump_p3;							/*	����3				*/
	int		pump_p4;							/*	����4				*/
} CMD_U_PARAM;

/*	�|���v�ғ���											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		ope_amount;							/*	�ғ���				*/
} CMD_J_PARAM;

/*	�G���W���I�C�������c����											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		change_h;							/*	�����c����			*/
} CMD_EC_PARAM;

/*	�R���t�B���^�����c����											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		change_h;							/*	�����c����			*/
} CMD_FC_PARAM;

/*	�쓮���t�B���^�����c����											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		change_h;							/*	�����c����			*/
} CMD_HC_PARAM;

/*	�쓮�������c����											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		change_h;							/*	�����c����			*/
} CMD_LC_PARAM;

/*	�I�[�o�[���[�h��Ԏ���											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		state_h;							/*	��Ԏ���			*/
} CMD_OV_PARAM;

/*	�R�����x											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		fuel_tmp;							/*	�R�����x			*/
} CMD_FT_PARAM;

/*	�R�����ʒl											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		fuel_dt;							/*	�R�����ʒl			*/
} CMD_FS_PARAM;

/*	�T�[�r�X�f�f(WEB�Ǘ��ԍ�)											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	char	group_cd[GROUP_CD_MAX_LEN+1];		/*	�O���[�v�R�[�h		*/
	char	sindan_no[DIAGNOSIS_NO_MAX_LEN+1];	/*	�f�f�Ǘ�No			*/
} CMD_SD1_PARAM;

/*	�T�[�r�X�f�f(�T�[�r�X�f�f���)										*/
typedef struct STRCT_CMD_SD2_PARAM {
	char	cmd_all[BODY_LINE_MAX_LEN+1];				/*	�R�}���h�s�S��		*/
	char	diagnoisi_data[DIAGNOSIS_DATA_MAX_LEN+1];	/*	�O���[�v�R�[�h + �f�[�^�R�[�h + �f�[�^	*/
														/*	�f�[�^�̎󂯓n���d�l�s���̂��ߑS�Ă��ЂƂɂ܂Ƃ߂�	*/
	struct  STRCT_CMD_SD2_PARAM *parent;
	struct  STRCT_CMD_SD2_PARAM *next;
} CMD_SD2_PARAM;

/*	�T�[�r�X�f�f(����)													*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	char	group_cd[GROUP_CD_MAX_LEN+1];		/*	�O���[�v�R�[�h		*/
	char	sd_status[MAIL_STATUS_MAX_LEN+1];	/*	����	*/
} CMD_SD3_PARAM;

/*	�A�����[�^�ύX											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	hs_r_cont[MAIL_CONT_MAX_LEN+1];		/*	�A�����[�^�ύX�v���l	*/
	char	reply[MAIL_STATUS_MAX_LEN+1];		/*	����	*/
} CMD_HS_PARAM;

/*	�G���W���I�C�������c���ԕύX											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	he_r_cont[MAIL_CONT_MAX_LEN+1];		/*	�G���W���I�C�������c����	*/
	char	reply[MAIL_STATUS_MAX_LEN+1];		/*	����	*/
} CMD_HE_PARAM;

/*	�R��̨�������c���ԕύX											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	hf_r_cont[MAIL_CONT_MAX_LEN+1];		/*	�R��̨�������c����	*/
	char	reply[MAIL_STATUS_MAX_LEN+1];		/*	����	*/
} CMD_HF_PARAM;

/*	�쓮��̨�������c���ԕύX											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��			*/
	char	hh_r_cont[MAIL_CONT_MAX_LEN+1];		/*	�쓮��̨�������c����	*/
	char	reply[MAIL_STATUS_MAX_LEN+1];		/*	����	*/
} CMD_HH_PARAM;

/*	�쓮�������c���ԕύX											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	char	hl_r_cont[MAIL_CONT_MAX_LEN+1];		/*	�쓮�������c����	*/
	char	reply[MAIL_STATUS_MAX_LEN+1];		/*	����	*/
} CMD_HL_PARAM;

/*	�̏ᗈ�����											*/
typedef struct STRCT_CMD_AH_PARAM {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��	*/
	int		tousi_no;							/*	�ʂ��ԍ�		*/
	char	raireki1[BODY_LINE_MAX_LEN+1];		/*	�̏ᗈ���O�P	*/
	char	raireki2[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���O�Q	*/
	char	raireki3[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���O�R	*/
	char	raireki4[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���O�S	*/
	char	raireki5[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���O�T	*/
	char	raireki6[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���O�U	*/
	char	raireki7[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���O�V	*/
	char	raireki8[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���O�W	*/
	char	raireki9[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���O�X	*/
	char	raireki10[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���P�O	*/
	char	raireki11[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���P�P	*/
	char	raireki12[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���P�Q	*/
	char	raireki13[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���P�R	*/
	char	raireki14[RAIREKI_MAX_LEN+1];		/*	�̏ᗈ���P�S	*/
	int		hour_meter;							/*	�A�����[�^		*/
	struct STRCT_CMD_AH_PARAM *parent;
	struct STRCT_CMD_AH_PARAM *next;
} CMD_AH_PARAM;

/*	���J�g�����R���g���[���p�[�cNo											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	/*	�R�}���h�s�S��			*/
	char	mc_pno[MC_PNO_MAX_LEN+1];		/*	�p�[�cNo	*/
} CMD_PN_PARAM;

/*	���J�g�����R���g���[���\�t�gVer										*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	/*	�R�}���h�s�S��			*/
	char	mc_ver[MC_VER_MAX_LEN+1];		/*	�\�t�gver	*/
} CMD_VR_PARAM;

/*	�x��A���Ȑf�f(Tier4a�g����)										*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	char	alarm_cd[CMD_MAX_LEN+1];			/*	�x��R�[�h			*/
	char	error_cd[ERROR_CD_LEN+1];			/*	�G���[�R�[�h		*/
	int		alarm_status;						/*	����/����			*/
	char	yymmddhh24mi[YYMMDDHHMI_MAX_LEN+1];	/*	�R�}���h			*/
	char	eg_status[2];						/*	E/G�ғ����			*/
} CMD_XX_PARAM;

/*	�R��											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int	fuel_cons_amount;						/*	�R�������			*/
	int	power_on_h;								/*	�ғ�����			*/
} CMD_NP_PARAM;

/*	[TIER4A]���[�h�ʔR�������											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		fuel_cons_h_mode;					/*	�R�������(H���[�h)	*/
	int		fuel_cons_s_mode;					/*	�R�������(S���[�h)	*/
	int		fuel_cons_e_mode;					/*	�R�������(E���[�h)	*/
} CMD_MC_PARAM;

/*	[TIER4A]���[�h�ʉғ�����											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		fuel_pon_h_mode;		/*	�ғ�����(H���[�h)	*/
	int		fuel_pon_s_mode;		/*	�ғ�����(S���[�h)	*/
	int		fuel_pon_e_mode;		/*	�ғ�����(E���[�h)	*/
} CMD_MT_PARAM;

/*	[Tier4A]���񑀍쎞��												*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		turning_h;							/*	���񑀍쎞��		*/
} CMD_SW_PARAM;

/*	[Tier4A]�����l(���p)												*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		adjust;								/*	�����l				*/
} CMD_ADJUST_PARAM;

/*	[Tier4A]�G���W���n����											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		eg_st_count;						/*	�����l				*/
} CMD_ST_PARAM;

/*	DPF�ڋl�܂背�x��													*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	char	dpf_level[10 + 1];					/*	DPF�ڋl�܂背�x��	*/
} CMD_SL_PARAM;

/*	����																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	char	td_value[5 + 1];					/*	����(+/-MISS)		*/
	char	td_status[MAIL_STATUS_MAX_LEN+1];	/*	����	*/
} CMD_TD_PARAM;

/*	SSID������												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	char	ssid_status[2 + 1];					/*	SSID�ύX����		*/
	char	ssid_value[5 + 1];					/*	SSID�����l			*/
} CMD_SSID_PARAM;

/*	�ėp�P																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		count;								/*	����				*/
	char	value00[CONST_C20+1];				/*	�l00				*/
	char	value01[CONST_C20+1];				/*	�l01				*/
	char	value02[CONST_C20+1];				/*	�l02				*/
	char	value03[CONST_C20+1];				/*	�l03				*/
	char	value04[CONST_C20+1];				/*	�l04				*/
	char	value05[CONST_C20+1];				/*	�l05				*/
	char	value06[CONST_C20+1];				/*	�l06				*/
	char	value07[CONST_C20+1];				/*	�l07				*/
	char	value08[CONST_C20+1];				/*	�l08				*/
	char	value09[CONST_C20+1];				/*	�l09				*/
	char	value10[CONST_C20+1];				/*	�l10				*/
	char	value11[CONST_C20+1];				/*	�l11				*/
	char	value12[CONST_C20+1];				/*	�l12				*/
	char	value13[CONST_C20+1];				/*	�l13				*/
	char	value14[CONST_C20+1];				/*	�l14				*/
	char	value15[CONST_C20+1];				/*	�l15				*/
	char	value16[CONST_C20+1];				/*	�l16				*/
	char	value17[CONST_C20+1];				/*	�l17				*/
	char	value18[CONST_C20+1];				/*	�l18				*/
	char	value19[CONST_C20+1];				/*	�l19				*/
	char	value20[CONST_C20+1];				/*	�l20				*/
	char	value21[CONST_C20+1];				/*	�l21				*/
	char	value22[CONST_C20+1];				/*	�l22				*/
	char	value23[CONST_C20+1];				/*	�l23				*/
	char	value24[CONST_C20+1];				/*	�l24				*/
	char	value25[CONST_C20+1];				/*	�l25				*/
	char	value26[CONST_C20+1];				/*	�l26				*/
} CMD_C20X5_PARAM;

/*	�ėp�Q																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		count;								/*	����				*/
	char	value00[CONST_C30+1];				/*	�l00				*/
	char	value01[CONST_C30+1];				/*	�l01				*/
	char	value02[CONST_C30+1];				/*	�l02				*/
	char	value03[CONST_C30+1];				/*	�l03				*/
	char	value04[CONST_C30+1];				/*	�l04				*/
	char	value05[CONST_C30+1];				/*	�l05				*/
	char	value06[CONST_C30+1];				/*	�l06				*/
	char	value07[CONST_C30+1];				/*	�l07				*/
	char	value08[CONST_C30+1];				/*	�l08				*/
	char	value09[CONST_C30+1];				/*	�l09				*/
	char	value10[CONST_C30+1];				/*	�l10				*/
} CMD_C30X10_PARAM;


/*	�ėp�R																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		count;								/*	����				*/
	char	value00[CONST_C30+1];				/*	�l00				*/
	char	value01[CONST_C30+1];				/*	�l01				*/
} CMD_C30X1_PARAM;

/*	�ėp�S																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		count;								/*	����				*/
	char	value00[CONST_C30+1];				/*	�l00				*/
	char	value01[CONST_C30+1];				/*	�l01				*/
	char	value02[CONST_C30+1];				/*	�l02				*/
	char	value03[CONST_C30+1];				/*	�l03				*/
	char	value04[CONST_C30+1];				/*	�l04				*/
	char	value05[CONST_C30+1];				/*	�l05				*/
} CMD_C30X5_PARAM;

/*	�ėp�T																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		count;								/*	����				*/
	char	key1[CONST_HANYO_KEY+1];			/*	�L�[�P				*/
	char	key2[CONST_HANYO_KEY+1];			/*	�L�[�Q				*/
	char	key3[CONST_HANYO_KEY+1];			/*	�L�[�R				*/
	char	key4[CONST_HANYO_KEY+1];			/*	�L�[�S				*/
	char	key5[CONST_HANYO_KEY+1];			/*	�L�[�T				*/
	char	reckey1[CONST_HANYO_KEY+1];			/*	�f�[�^�L�[			*/
	char	value01[CONST_HANYO_DATA+1];		/*	�f�[�^				*/
} CMD_HANYO_PARAM;


/*	�ėp�U																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		count;								/*	����([0]�ɍs��)*/
	int		value_count;						/*	(���̍s�̒l��)		*/
	char	value00[CONST_C20+1];				/*	�l00				*/
	char	value01[CONST_C20+1];				/*	�l01				*/
	char	value02[CONST_C20+1];				/*	�l02				*/
	char	value03[CONST_C20+1];				/*	�l03				*/
	char	value04[CONST_C20+1];				/*	�l04				*/
	char	value05[CONST_C20+1];				/*	�l05				*/
	char	value06[CONST_C20+1];				/*	�l06				*/
	char	value07[CONST_C20+1];				/*	�l07				*/
	char	value08[CONST_C20+1];				/*	�l08				*/
	char	value09[CONST_C20+1];				/*	�l09				*/
	char	value10[CONST_C20+1];				/*	�l10				*/
	char	value11[CONST_C20+1];				/*	�l11				*/
	char	value12[CONST_C20+1];				/*	�l12				*/
	char	value13[CONST_C20+1];				/*	�l13				*/
	char	value14[CONST_C20+1];				/*	�l14				*/
	char	value15[CONST_C20+1];				/*	�l15				*/
	char	value16[CONST_C20+1];				/*	�l16				*/
	char	value17[CONST_C20+1];				/*	�l17				*/
	char	value18[CONST_C20+1];				/*	�l18				*/
	char	value19[CONST_C20+1];				/*	�l19				*/
	char	value20[CONST_C20+1];				/*	�l20				*/
	char	value21[CONST_C20+1];				/*	�l21				*/
	char	value22[CONST_C20+1];				/*	�l22				*/
	char	value23[CONST_C20+1];				/*	�l23				*/
	char	value24[CONST_C20+1];				/*	�l24				*/
	char	value25[CONST_C20+1];				/*	�l25				*/
	char	value26[CONST_C20+1];				/*	�l26				*/
	char	value27[CONST_C20+1];				/*	�l27				*/
	char	value28[CONST_C20+1];				/*	�l28				*/
	char	value29[CONST_C20+1];				/*	�l29				*/
	char	value30[CONST_C20+1];				/*	�l30				*/
	char	value31[CONST_C20+1];				/*	�l31				*/
	char	value32[CONST_C20+1];				/*	�l32				*/
	char	value33[CONST_C20+1];				/*	�l33				*/
	char	value34[CONST_C20+1];				/*	�l34				*/
	char	value35[CONST_C20+1];				/*	�l35				*/
	char	value36[CONST_C20+1];				/*	�l36				*/
	char	value37[CONST_C20+1];				/*	�l37				*/
	char	value38[CONST_C20+1];				/*	�l38				*/
	char	value39[CONST_C20+1];				/*	�l39				*/
	char	value40[CONST_C20+1];				/*	�l40				*/
	char	value41[CONST_C20+1];				/*	�l41				*/
	char	value42[CONST_C20+1];				/*	�l42				*/
	char	value43[CONST_C20+1];				/*	�l43				*/
	char	value44[CONST_C20+1];				/*	�l44				*/
	char	value45[CONST_C20+1];				/*	�l45				*/
	char	value46[CONST_C20+1];				/*	�l46				*/
	char	value47[CONST_C20+1];				/*	�l47				*/
	char	value48[CONST_C20+1];				/*	�l48				*/
	char	value49[CONST_C20+1];				/*	�l49				*/
	char	value50[CONST_C20+1];				/*	�l50				*/
} CMD_HANYO06_PARAM;

/*	�ėp�V																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	�R�}���h�s�S��		*/
	int		count;								/*	����				*/
	char	value00[CONST_C200+1];				/*	�l00				*/
	char	value01[CONST_C200+1];				/*	�l01				*/
	char	value02[CONST_C200+1];				/*	�l02				*/
	char	value03[CONST_C200+1];				/*	�l03				*/
	char	value04[CONST_C200+1];				/*	�l04				*/
	char	value05[CONST_C200+1];				/*	�l05				*/
} CMD_C200X5_PARAM;


/*	���[�����\���̒�`													*/
typedef struct	{
	char	header[HEADER_MAX_LEN + 1];					/*	���[���w�b�_�S��		*/
	char	body[BODY_MAX_LEN + 1];						/*	���[���{�f�B�[�S��		*/
	char	from_mailaddr[MAIL_ADDR_MAX_LEN + 1];		/*	�w�b�_From�A�h���X		*/
	char	to_mailaddr[MAIL_ADDR_MAX_LEN + 1];			/*	�w�b�_To�A�h���X		*/
	char	body_to_mailaddr[MAIL_ADDR_MAX_LEN + 1];	/*	�{����To�A�h���X		*/
	int		nc_status_ng;								/*	"NG STATUS NG"�L��		*/
	int		no_mailbox;									/*	"no mailbox"�L��		*/
	char	sr_typ[1+1];								/*	����M�敪				*/
	char	mail_typ[MAIL_TYP_MAX_LEN+1];				/*	���[���^�C�v			*/
	int		s_flg;										/*	�����t���O				*/
	char	message_id[MESSAGE_ID_LEN + 1];				/*	���b�Z�[�WID(���[��)*/
} MAIL_INFO;

/*	�A�v���P�[�V�������O�o�͍\����											*/
typedef struct	{
	char	datfile[1024];
	char	equipno[20];
	char	mailaddr[128];
	int		seq;
	int		lineno;
} APLOG_INFO;
/* ------------------------------------------------------------------------ */
/*	�O���V���{���Q�Ɛ錾													*/
/* ------------------------------------------------------------------------ */

char AT_DBCON_1[10];




