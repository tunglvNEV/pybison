/* ======================================================================== */
/*	コベルコ建機様向け用　稼動機管理システム				*/
/*	ファイル名	：	merit_bat.h												*/
/*	説明		：	バッチ系処理の共通ヘッダファイル						*/
/* ------------------------------------------------------------------------ */
/*	作成	SKCS	2009.02.01												*/
/*	更新	SKCS	2009.07.21	他社機対応									*/
/*			KSC		2011.10.25	ミニ流用：国外／オーブコム２対応			*/
/* ======================================================================== */

/* ------------------------------------------------------------------------ */
/*	定数の定義																*/
/* ------------------------------------------------------------------------ */

#define		APLOG_DIR		"/it/log/"	/*	アプリログ格納ディレクトリ		*/
#define		MAIL_FILENM_LEN	255	/*	受信テキスト(メール)ファイル名の長さ	*/

#define		MAX_MAIL_LINE	200	/*	(正常系/空行を除く)メール行最大許容数	*/
#define		MAX_CMD_PARAM	20	/*	(正常系)コマンドパラメータ最大許容数	*/

#define		LOCK_FILENAME	"/it/lock/ml_ent%s.lck"/*	LOCKファイル名	*/

#define		MAIL_SETDIR		"/it/%s/set_mail/"	/*	メール配置DIR		*/
#define		MAIL_WORKDIR	"/it/%s/work_mail/"/*	メール作業DIR		*/

#define		CHR_PHONE_PREFIX	'k'	/* メールアドレスの電話番号	直前の文字	*/
#define		CHR_PHONE_POSTFIX	'@'	/* 							直後の文字	*/

#define		DATA_ARRAY_MAX	50			/*	コマンドデータ配列の最大数		*/
#define		DIR_NAME_MAX	1024		/*	ディレクトリ名最大長			*/
#define		CMD_LEN_MAX		1024		/*	Unixコマンド長さ				*/
#define		PAUSE_TIMES_MAX	10			/*	実行抑止時間設定最大数			*/

/*	メールヘッダ関連														*/
#define		MAIL_ADDR_MAX_LEN	128
#define		SUBJECT_MAX_LEN		256
#define		SR_TYP_MAX_LEN		1
#define		EVENTCD_MAX_LEN		3
#define		MESSAGEID_MAX_LEN	1000
#define		BODY_MAX_LEN		2000
#define		HEADER_MAX_LEN		2000
#define		MESSAGE_ID_LEN		256

#define		CHR_ML_ADDR_PREFIX		'<'		/* メールアドレス	直前の文字	*/
#define		CHR_ML_ADDR_POSTFIX		'>'		/* メールアドレス	直後の文字	*/

#define		GPS_ERROR_LATITUDE	"XXX.XXXX"
#define		GPS_ERROR_LONGITUDE	"XXXX.XXXX"

#define		MAIL_TKN_HEADER_FROM				"From: "
#define		MAIL_TKN_HEADER_TO					"To: "
#define		MAIL_TKN_MESSAGE_ID					"Message-Id: "
#define		MAIL_TKN_BODY_TO					"To: "
#define		MAIL_TKN_NG_USER_UNKNOWN			"User unknown"
#define		MAIL_TKN_NG_NC_STATUS_NG			"NC status NG"

/*	その他定数																*/

/*	DB接続AT			*/
#define		DBCON_1			"FOR_LOCK"

/* ------------------------------------------------------------------------ */
/*	型の定義																*/
/* ------------------------------------------------------------------------ */

/*	受信メッセージ格納バッファの構造定義									*/
typedef struct {
	int		mtype;						/*	メッセージタイプ				*/
	char	mtext[4];					/*	メッセージテキスト				*/
} MSGBUF;

/*	環境変数情報格納域の定義												*/
typedef struct	{
	int		mail_msg_ky;				/*	メッセージキューのキー			*/
	char	oracle_connect_string[256];	/*	Oracle接続文字列				*/
	char	snd_ml_shell[DIR_NAME_MAX];	/*	警報通知メール送信用シェル		*/
	char	from_address[256];			/*	警報通知メール発信アドレス		*/
	char	reply_address[256];			/*	警報通知メール発信アドレス		*/
	char	mail_work_dir[1024 + 1];	/*	メール作業DIR					*/
	char	mail_set_dir[1024 + 1];		/*	メール格納DIR(ml_rcvと同値)		*/
	char	lock_file_name[1024 + 1];	/*	ロックファイル名				*/
	char	time_log_str[4+1];			/*	タイムログ出力開始時間			*/
	char	time_log_stp[4+1];			/*	タイムログ出力終了時間			*/
	char	pause_str_times[4+1][PAUSE_TIMES_MAX];	/*	実行抑止開始時間	*/
	char	pause_stp_times[4+1][PAUSE_TIMES_MAX];	/*	実行抑止終了時間	*/
} ENVDATA;

#define		BODY_LINE_MAX_LEN	1000			/*	コマンド行全文の最大数	*/
#define		EQUIP_NO_MAX_LEN	20				/*	設備番号の最大数		*/
#define		CUST_EQUIP_NO_MAX_LEN	25			/*	客先管理番号の最大数	*/
#define		TIME_MAX_LEN		20				/*	日時項目の最大数		*/
#define		PROC_NAME_MAX_LEN	9				/*	プロセス名の最大数		*/
#define		MAIL_TYP_MAX_LEN	3				/*	メールタイプの最大数	*/
#define		LATITUDE_MAX_LEN	10				/*	緯度の最大数			*/
#define		LONGITUDE_MAX_LEN	10				/*	経度の最大数			*/
#define		TEL_NO_MAX_LEN		20				/*	電話番号の最大数		*/
#define		CUST_TEL_NO_MAX_LEN	20				/*	(顧客)電話番号の最大数	*/
#define		IP_ADDRESS_MAX_LEN	15				/*	IPアドレスの最大数		*/
#define		ORA_ERR_MSG_MAX_LEN	1024			/*	Oracleメッセージ用最大数*/
#define		ERR_MSG_MAX_LEN		1024			/*	エラーメッセージの最大数*/
#define		CUST_NM				60				/*	顧客名の最大長			*/
#define		SHOP_CD_MAX_LEN		6				/*	営業所コードの最大長	*/
#define		EQUIP_SERIAL_NO_MAX_LEN	18			/*	設備シリアル番号の最大長*/
#define		EQUIP_NM_MAX_LEN	20				/*	設備テキストの最大長	*/
#define		GROUP_CD_MAX_LEN	10				/*	グループコードの最大長	*/
#define		EGN_STA_MAX_LEN		6				/*	エンジン状態の最大長	*/
#define		MAIL_CONT_MAX_LEN	40				/*	メール内容の最大値		*/
#define		MAIL_STATUS_MAX_LEN	8				/*	メール状態の最大値		*/
#define		SERIAL_NO_MAX_LEN	40				/*	ITCシリアルNOの最大数	*/
#define		CMD_MAX_LEN			2				/*	コマンドの最大数		*/
#define		YYMMDDHHMI_MAX_LEN	10				/*	年月日時の最大数		*/
#define		DATA_CD_MAX_LEN		2				/*	データコードの最大長	*/
#define		DIAGNOSIS_DATA_MAX_LEN	36			/*	サービス診断情報の最大長*/
#define		DIAGNOSIS_NO_MAX_LEN	14			/*	診断管理Noの最大長		*/
#define		MC_PNO_MAX_LEN		15				/*	メカトロコントローラパーツNoの最大長	*/
#define		MC_VER_MAX_LEN		5				/*	メカトロコントローラパーツVerの最大長	*/
#define		RAIREKI_MAX_LEN		2				/*	故障来歴の最大長	*/
#define		HOUR_METER_MAX_LEN	6				/*	アワメータの最大長	*/
#define		ENGINE_ON_OF_MAX_COUNT	100			/*	エンジンON/OF繰り返し数(規定では50セットだが51セットがあったため拡張(2011.12))	*/
#define		SERVICE_DIAG_MAX_COUNT	50			/*	サービス診断情報繰り返し数(特に規定なし?)	*/
#define		ALARM_INQUIRY_MAX_COUNT	50			/*	故障来歴繰り返し数(特に規定なし?)	*/
#define		MC_PNO_MAX_LEN	15					/*	ﾒｶﾄﾛｺﾝﾄﾛｰﾗﾊﾟｰﾂNOの最大数	*/
#define		MC_VER_MAX_LEN	5					/*	ﾒｶﾄﾛｺﾝﾄﾛｰﾗｿﾌﾄverの最大数	*/
#define		ITC_VERSION		10					/*	ITCバージョンの桁数			*/
#define		ERROR_CD_LEN	20					/*	[Tier4A]自己診断エラーコード*/
#define		ALARM_CD_MAX_LEN	2				/*	警報コード					*/

#define		MAX_HOZEN_PARAM		50
#define		MAX_HANYO_PARAM		20				/*	稼働実績への拡張情報レコード数	*/
#define		CONST_C20			20
#define		CONST_C30			30
#define		CONST_C200			200

#define		MAX_HANYO_REC		1 + 20			/*	汎用ヘッダ行＋汎用データ行	*/
#define		CONST_HANYO_KEY		20				/*	汎用KEY情報サイズ			*/
#define		CONST_HANYO_DATA	250				/*	汎用	*/
#define		MAX_FDFR_REC		20				/*	故障診断(許容行数)	*/
#define		CONST_FDFR_DATA		50				/*	故障診断の値のバイト数	*/

#define		MAX_AE_REC			100			/*	衝突軽減機能切り替え情報(最大１００行)	*/
#define		MAX_AR_REC			26			/*	衝突軽減レポート（AR0～AR25の26行）	*/
#define		MAX_RR_REC			3			/*	再生診断（RR0～RR2の3行）	*/
#define		MAX_KL_REC			45			/*	K-LOAD作業データ(最大45行)	*/


/*	メールタイプ(内部用)定数													*/
#define		MTYP_BATCH_DAYTIME		"BATCH_D"	/*	昼バッチ					*/
#define		MTYP_BATCH_NIGHT_OPE	"BATCH_N1"	/*	夜間バッチ(稼動)			*/
#define		MTYP_BATCH_NIGHT_NOPE	"BATCH_N2"	/*	夜間バッチ(非稼動)			*/
#define		MTYP_BATCH_NIGHT_EXP	"BATCH_N3"	/*	夜間バッチ(例外)			*/
#define		MTYP_SC					"SC"		/*	侵入警報定義(SC)			*/
#define		MTYP_SA					"SA"		/*	エリア外警報定義(SA)		*/
#define		MTYP_BT					"BT"		/*	バッテリーはずし警報定義(BT)*/
#define		MTYP_RT					"RT"		/*	機械状態問い合わせ(RT応答)	*/
#define		MTYP_AM					"AM"		/*	侵入警報有効時間設定(AM応答)*/
#define		MTYP_CL					"CL"		/*	エリア設定(CL応答)			*/
#define		MTYP_CM0				"CM0"		/*	通信停止設定(CM0応答)		*/
#define		MTYP_CM1				"CM1"		/*	通信再開設定(CM1応答)		*/
#define		MTYP_CT0				"CT0"		/*	通信テスト(CT0応答)			*/
#define		MTYP_CT1				"CT1"		/*	通信量確認(CT1応答)			*/
#define		MTYP_HS					"HS"		/*	アワメータ変更(HS応答)		*/
#define		MTYP_HE					"HE"		/*	ｴﾝｼﾞﾝｵｲﾙ交換残時間変更(HE応答) */
#define		MTYP_HF					"HF"		/*	燃料ﾌｨﾙﾀ交換残時間変更(HF応答) */
#define		MTYP_HH					"HH"		/*	作業油ﾌｨﾙﾀ交換残時間変更(HH応答) */
#define		MTYP_HL					"HL"		/*	作業油交換残時間変更(HL応答) */
#define		MTYP_NG					"NG_MAIL"	/*	NGメール					*/
#define		MTYP_AH					"AH"		/*	故障来歴					*/
#define		MTYP_SD					"SD"		/*	サービス診断				*/
#define		MTYP_RM					"RM"		/*	メカトロ情報取得応答(V7)	*/
#define		MTYP_XX					"XX"		/*	自己診断					*/
#define		MTYP_XX_V7				"XX_V7"		/*	自己診断(V7)				*/
#define		MTYP_ONLY_POS			"ONLY_POS"	/*	位置情報のみ				*/
#define		MTYP_TD					"TD"		/*	時差設定(TD応答)			*/
#define		MTYP_BATCH_OPE			"BATCH1"	/*	１０型バッチ（稼働）		*/
#define		MTYP_BATCH_NOPE			"BATCH2"	/*	１０型バッチ（非稼働）		*/
#define		MTYP_SS					"SS"		/*	SIMカード抜去警報			*/
#define		MTYP_SR					"SR"		/*	通信アンテナ切断警報		*/
#define		MTYP_SG					"SG"		/*	GPSアンテナ切断警報			*/
#define		MTYP_SU					"SU"		/*	VCU通信不能警報				*/
#define		MTYP_HD					"HD"		/*	健康診断指示応答			*/
#define		MTYP_HQ					"HQ"		/*	健康診断実施可否選択結果	*/
#define		MTYP_HP					"HP"		/*	健康診断結果				*/
#define		MTYP_DG					"DG"		/*	遠隔DL応答					*/
#define		MTYP_HANYO				"HANYO"		/*	汎用メール形式				*/
#define		MTYP_FDFR				"FDFR"		/*	故障診断					*/
#define		MTYP_HDHQHP				"HDHQHP"	/*	健康診断					*/
#define		MTYP_LKOK				"LKOK"		/*	遠隔ロック設定応答			*/
#define		MTYP_AE					"AE"		/*	衝突軽減機能切換			*/
#define		MTYP_AR					"AR"		/*	衝突軽減レポート			*/
#define		MTYP_RR					"RR"		/*	再生診断					*/
#define		MTYP_SSID				"SSID"		/*	SSID書込み					*/
#define		MTYP_KL					"KL"		/*	K-LOAD作業データ			*/

#define		MTYP_XXXX				"XXXX"		/*	想定外						*/


/*	設備関連項目(顧客情報)構造体	*/
/*typedef struct	{*/
/*	char	equip_no[EQUIP_NO_MAX_LEN + 1];			/*	設備番号			*/
/*	char	cust_equip_no[CUST_EQUIP_NO_MAX_LEN];	/*	客先管理番号		*/
/*	char	cust_nm[CUST_NM+1];						/*	顧客名				*/
/*	char	cust_tel_no[CUST_TEL_NO_MAX_LEN+1];		/*	顧客電話番号		*/
/*} EQUIP_INFO;*/

/*	プロセス共通構造体	*/
typedef struct	{
	char	sysdate[TIME_MAX_LEN + 1];			/*	システム共通日時		*/
	char	proc[PROC_NAME_MAX_LEN + 1];		/*	プロセス名				*/
	char	exec_proc[20 + 1];					/*	実行ファイル名(ログ用)	*/
} PROC_COM_PARAM;

/*	メール共通構造体														*/
typedef struct	{
	char	equip_no[EQUIP_NO_MAX_LEN + 1];		/*	設備番号				*/
	int		seq;								/*	SEQ						*/
	char	mail_date[TIME_MAX_LEN + 1];		/*	位置日時(年月日時分秒)	*/
	char	err_msg[ERR_MSG_MAX_LEN + ORA_ERR_MSG_MAX_LEN + 1];	/*	エラーMSG	*/
	int		mail_type_flg;						/*	メール種別(0:通常,1:メンテ)	*/
	int		mail_ng_flg;						/*	NGメールフラグ(0:通常,1:NG)	*/
	char	mail_type[10 + 1];					/*	メールタイプ			*/
	char	mail_type_forlog[MAIL_TYP_MAX_LEN + 1];	/*	メールタイプ(ログ出力用)*/
	char	mail_file_nm[MAIL_FILENM_LEN + 1];	/*	解析中メールファイル名	*/
	char	from_mailaddr[MAIL_ADDR_MAX_LEN + 1];	/*	送信元メールアドレス*/
	char	to_mailaddr[MAIL_ADDR_MAX_LEN + 1];	/*	送信先メールアドレス	*/
	char	tel_no[TEL_NO_MAX_LEN + 1];			/*	電話番号				*/
	char	itc_serial_no[SERIAL_NO_MAX_LEN + 1];	/*	ITCシリアルNO		*/
	char	itc_version[ITC_VERSION + 1];			/*	ITCバージョン		*/
	int		keiho_stop;							/* 警報メール通知処理抑止	*/
} CMD_COM_PARAM;


/*	位置コマンド構造体														*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	latitude[LATITUDE_MAX_LEN+1];		/*	緯度					*/
	char	longitude[LONGITUDE_MAX_LEN+1];		/*	経度					*/
	char	hh24middmm[TIME_MAX_LEN + 1];		/*	時分日月				*/
	int		chuuki;								/*	駐機状態				*/
} CMD_POS_PARAM;

/*	アワメータコマンド構造体												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		power_on_h;							/*	稼働時間				*/
} CMD_H_PARAM;

/*	エリア判定コマンド構造体												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		area_flg;							/*	ｴﾘｱ内外ﾌﾗｸﾞ				*/
} CMD_A_PARAM;

/*	エンジン稼働情報コマンド構造体											*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];			/*	コマンド行全文			*/
	char	engine_state_flg[EGN_STA_MAX_LEN + 1];	/*	エンジン状態ﾌﾗｸﾞ		*/
} CMD_EG_PARAM;

/*	侵入警報有効時間設定(AMOF)コマンド構造体								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	hh24mi[TIME_MAX_LEN + 1];			/*	時分					*/
	char	am_r_status[MAIL_STATUS_MAX_LEN+1];	/*	応答					*/
} CMD_AMOF_PARAM;

/*	侵入警報有効時間設定(AMON)コマンド構造体								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	hh24mi[TIME_MAX_LEN + 1];			/*	時分					*/
	char	am_r_status[MAIL_STATUS_MAX_LEN+1];	/*	応答					*/
} CMD_AMON_PARAM;

/*	侵入警報有効時間設定(AM)コマンド構造体									*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	hold_al[TIME_MAX_LEN + 1];			/*	曜日毎有効指定			*/
	char	am_r_status[MAIL_STATUS_MAX_LEN+1];	/*	応答					*/
} CMD_AM_PARAM;

/*	エリア設定コマンド構造体												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	latitude1[LATITUDE_MAX_LEN+1];		/*	緯度1					*/
	char	longitude1[LONGITUDE_MAX_LEN+1];	/*	経度1					*/
	char	latitude2[LATITUDE_MAX_LEN+1];		/*	緯度2					*/
	char	longitude2[LONGITUDE_MAX_LEN+1];	/*	経度2					*/
	char	cl_r_status[MAIL_STATUS_MAX_LEN+1];	/*	応答					*/
} CMD_CL_PARAM;

/*	侵入警報コマンド構造体													*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	yymmddhh24mi[TIME_MAX_LEN + 1];		/*	年月日時分				*/
} CMD_SC_PARAM;

/*	通信停止応答コマンド構造体												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	cm0_r_status[MAIL_STATUS_MAX_LEN+1];	/*	通信停止応答			*/
} CMD_CM0_PARAM;

/*	通信再開応答コマンド構造体												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	cm1_r_status[MAIL_STATUS_MAX_LEN+1];	/*	通信再開応答			*/
} CMD_CM1_PARAM;

/*	通信テスト応答(電話番号)コマンド構造体									*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	ct0_tel_no[TEL_NO_MAX_LEN + 1];		/*	電話番号				*/
} CMD_D0_PARAM;

/*	通信テスト応答(IPアドレス)コマンド構造体								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];				/*	コマンド行全文	*/
	char	ct0_ip_address[IP_ADDRESS_MAX_LEN + 1];		/*	IPアドレス		*/
} CMD_D1_PARAM;

/*	通信テスト応答(西暦)コマンド構造体										*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	ct0_sei_y[TIME_MAX_LEN + 1];		/*	西暦日付				*/
} CMD_D2_PARAM;

/*	通信テスト応答(メカトロ有無)コマンド構造体								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		ct0_mechatro;						/*	メカトロ有無ﾌﾗｸﾞ		*/
} CMD_D3_PARAM;

/*	通信確認応答(受信メール総容量)コマンド構造体								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		ct1_receive_byte;					/*	受信メール容量			*/
} CMD_M0_PARAM;

/*	通信確認応答(送信メール総容量)コマンド構造体								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		ct1_send_byte;						/*	送信メール容量			*/
} CMD_M1_PARAM;

/*	通信確認応答(受信メール数)コマンド構造体								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		ct1_receive_mail;					/*	受信メール数			*/
} CMD_M2_PARAM;

/*	通信確認応答(送信メール数)コマンド構造体								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		ct1_send_mail;						/*	送信メール数			*/
} CMD_M3_PARAM;

/*	通信確認応答(リトライ回数)コマンド構造体								*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		ct1_retry;							/*	リトライ回数			*/
} CMD_M4_PARAM;

/*	通信量確認応答(予備１)コマンド構造体							*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文	*/
	int		ct1_reserve1;						/*	予備１			*/
} CMD_M5_PARAM;

/*	通信量確認応答(予備２)コマンド構造体							*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文	*/
	int		ct1_reserve2;						/*	予備２			*/
} CMD_M6_PARAM;

/*	通信量確認応答(予備３)コマンド構造体							*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文	*/
	int		ct1_reserve3;						/*	予備３			*/
} CMD_M7_PARAM;

/*	通信量確認応答(予備４)コマンド構造体							*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文	*/
	int		ct1_reserve4;						/*	予備４			*/
} CMD_M8_PARAM;

/*	エリア外警報コマンド構造体												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		abnormal_flg;						/*	異常フラグ(発生/解除)	*/
} CMD_SA_PARAM;

/*	バッテリ外し警報コマンド構造体											*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		abnormal_flg;						/*	異常フラグ(発生/解除)	*/
} CMD_BT_PARAM;

/*	エンジン始動時間											*/
typedef struct STRCT_CMD_T_PARAM	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	yymmddhh24mi[TIME_MAX_LEN + 1];		/*	年月日時分				*/
	struct STRCT_CMD_T_PARAM *parent;
	struct STRCT_CMD_T_PARAM *next;
} CMD_T_PARAM;

/*	エンジン停止時間											*/
typedef struct STRCT_CMD_P_PARAM	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	yymmddhh24mi[TIME_MAX_LEN + 1];		/*	年月日時分				*/
	struct STRCT_CMD_P_PARAM *parent;
	struct STRCT_CMD_P_PARAM *next;
} CMD_P_PARAM;

/*	無操作時間											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		idle_h;								/*	無操作時間				*/
} CMD_I_PARAM;

/*	走行時間											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		running_h;							/*	走行時間				*/
} CMD_R_PARAM;

/*	ハイリーチ使用時間											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		high_r_h;							/*	ハイリーチ使用時間		*/
} CMD_C_PARAM;

/*	N&B使用時間											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		nb_h;								/*	N&B使用時間				*/
} CMD_N_PARAM;

/*	燃料残量											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	int		fuel_per;							/*	燃料残量				*/
} CMD_F_PARAM;

/*	エンジン水温分布									*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		e_temp_1;							/*	水温1				*/
	int		e_temp_2;							/*	水温2				*/
	int		e_temp_3;							/*	水温3				*/
	int		e_temp_4;							/*	水温4				*/
} CMD_W_PARAM;

/*	ポンプ圧力分布									*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		pump_p1;							/*	圧力1				*/
	int		pump_p2;							/*	圧力2				*/
	int		pump_p3;							/*	圧力3				*/
	int		pump_p4;							/*	圧力4				*/
} CMD_U_PARAM;

/*	ポンプ稼動量											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		ope_amount;							/*	稼動量				*/
} CMD_J_PARAM;

/*	エンジンオイル交換残時間											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		change_h;							/*	交換残時間			*/
} CMD_EC_PARAM;

/*	燃料フィルタ交換残時間											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		change_h;							/*	交換残時間			*/
} CMD_FC_PARAM;

/*	作動油フィルタ交換残時間											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		change_h;							/*	交換残時間			*/
} CMD_HC_PARAM;

/*	作動油交換残時間											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		change_h;							/*	交換残時間			*/
} CMD_LC_PARAM;

/*	オーバーロード状態時間											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		state_h;							/*	状態時間			*/
} CMD_OV_PARAM;

/*	燃料温度											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		fuel_tmp;							/*	燃料温度			*/
} CMD_FT_PARAM;

/*	燃料識別値											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		fuel_dt;							/*	燃料識別値			*/
} CMD_FS_PARAM;

/*	サービス診断(WEB管理番号)											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	char	group_cd[GROUP_CD_MAX_LEN+1];		/*	グループコード		*/
	char	sindan_no[DIAGNOSIS_NO_MAX_LEN+1];	/*	診断管理No			*/
} CMD_SD1_PARAM;

/*	サービス診断(サービス診断情報)										*/
typedef struct STRCT_CMD_SD2_PARAM {
	char	cmd_all[BODY_LINE_MAX_LEN+1];				/*	コマンド行全文		*/
	char	diagnoisi_data[DIAGNOSIS_DATA_MAX_LEN+1];	/*	グループコード + データコード + データ	*/
														/*	データの受け渡し仕様不明のため全てをひとつにまとめる	*/
	struct  STRCT_CMD_SD2_PARAM *parent;
	struct  STRCT_CMD_SD2_PARAM *next;
} CMD_SD2_PARAM;

/*	サービス診断(応答)													*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	char	group_cd[GROUP_CD_MAX_LEN+1];		/*	グループコード		*/
	char	sd_status[MAIL_STATUS_MAX_LEN+1];	/*	応答	*/
} CMD_SD3_PARAM;

/*	アワメータ変更											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	hs_r_cont[MAIL_CONT_MAX_LEN+1];		/*	アワメータ変更要求値	*/
	char	reply[MAIL_STATUS_MAX_LEN+1];		/*	応答	*/
} CMD_HS_PARAM;

/*	エンジンオイル交換残時間変更											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	he_r_cont[MAIL_CONT_MAX_LEN+1];		/*	エンジンオイル交換残時間	*/
	char	reply[MAIL_STATUS_MAX_LEN+1];		/*	応答	*/
} CMD_HE_PARAM;

/*	燃料ﾌｨﾙﾀ交換残時間変更											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	hf_r_cont[MAIL_CONT_MAX_LEN+1];		/*	燃料ﾌｨﾙﾀ交換残時間	*/
	char	reply[MAIL_STATUS_MAX_LEN+1];		/*	応答	*/
} CMD_HF_PARAM;

/*	作動油ﾌｨﾙﾀ交換残時間変更											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文			*/
	char	hh_r_cont[MAIL_CONT_MAX_LEN+1];		/*	作動油ﾌｨﾙﾀ交換残時間	*/
	char	reply[MAIL_STATUS_MAX_LEN+1];		/*	応答	*/
} CMD_HH_PARAM;

/*	作動油交換残時間変更											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	char	hl_r_cont[MAIL_CONT_MAX_LEN+1];		/*	作動油交換残時間	*/
	char	reply[MAIL_STATUS_MAX_LEN+1];		/*	応答	*/
} CMD_HL_PARAM;

/*	故障来歴情報											*/
typedef struct STRCT_CMD_AH_PARAM {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文	*/
	int		tousi_no;							/*	通し番号		*/
	char	raireki1[BODY_LINE_MAX_LEN+1];		/*	故障来歴０１	*/
	char	raireki2[RAIREKI_MAX_LEN+1];		/*	故障来歴０２	*/
	char	raireki3[RAIREKI_MAX_LEN+1];		/*	故障来歴０３	*/
	char	raireki4[RAIREKI_MAX_LEN+1];		/*	故障来歴０４	*/
	char	raireki5[RAIREKI_MAX_LEN+1];		/*	故障来歴０５	*/
	char	raireki6[RAIREKI_MAX_LEN+1];		/*	故障来歴０６	*/
	char	raireki7[RAIREKI_MAX_LEN+1];		/*	故障来歴０７	*/
	char	raireki8[RAIREKI_MAX_LEN+1];		/*	故障来歴０８	*/
	char	raireki9[RAIREKI_MAX_LEN+1];		/*	故障来歴０９	*/
	char	raireki10[RAIREKI_MAX_LEN+1];		/*	故障来歴１０	*/
	char	raireki11[RAIREKI_MAX_LEN+1];		/*	故障来歴１１	*/
	char	raireki12[RAIREKI_MAX_LEN+1];		/*	故障来歴１２	*/
	char	raireki13[RAIREKI_MAX_LEN+1];		/*	故障来歴１３	*/
	char	raireki14[RAIREKI_MAX_LEN+1];		/*	故障来歴１４	*/
	int		hour_meter;							/*	アワメータ		*/
	struct STRCT_CMD_AH_PARAM *parent;
	struct STRCT_CMD_AH_PARAM *next;
} CMD_AH_PARAM;

/*	メカトロンコントローラパーツNo											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	/*	コマンド行全文			*/
	char	mc_pno[MC_PNO_MAX_LEN+1];		/*	パーツNo	*/
} CMD_PN_PARAM;

/*	メカトロンコントローラソフトVer										*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];	/*	コマンド行全文			*/
	char	mc_ver[MC_VER_MAX_LEN+1];		/*	ソフトver	*/
} CMD_VR_PARAM;

/*	警報、自己診断(Tier4a拡張版)										*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	char	alarm_cd[CMD_MAX_LEN+1];			/*	警報コード			*/
	char	error_cd[ERROR_CD_LEN+1];			/*	エラーコード		*/
	int		alarm_status;						/*	発生/解除			*/
	char	yymmddhh24mi[YYMMDDHHMI_MAX_LEN+1];	/*	コマンド			*/
	char	eg_status[2];						/*	E/G稼動状態			*/
} CMD_XX_PARAM;

/*	燃費											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int	fuel_cons_amount;						/*	燃料消費量			*/
	int	power_on_h;								/*	稼働時間			*/
} CMD_NP_PARAM;

/*	[TIER4A]モード別燃料消費量											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		fuel_cons_h_mode;					/*	燃料消費量(Hモード)	*/
	int		fuel_cons_s_mode;					/*	燃料消費量(Sモード)	*/
	int		fuel_cons_e_mode;					/*	燃料消費量(Eモード)	*/
} CMD_MC_PARAM;

/*	[TIER4A]モード別稼働時間											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		fuel_pon_h_mode;		/*	稼働時間(Hモード)	*/
	int		fuel_pon_s_mode;		/*	稼働時間(Sモード)	*/
	int		fuel_pon_e_mode;		/*	稼働時間(Eモード)	*/
} CMD_MT_PARAM;

/*	[Tier4A]旋回操作時間												*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		turning_h;							/*	旋回操作時間		*/
} CMD_SW_PARAM;

/*	[Tier4A]調整値(共用)												*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		adjust;								/*	調整値				*/
} CMD_ADJUST_PARAM;

/*	[Tier4A]エンジン始動回数											*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		eg_st_count;						/*	調整値				*/
} CMD_ST_PARAM;

/*	DPF目詰まりレベル													*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	char	dpf_level[10 + 1];					/*	DPF目詰まりレベル	*/
} CMD_SL_PARAM;

/*	時差																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	char	td_value[5 + 1];					/*	時差(+/-MISS)		*/
	char	td_status[MAIL_STATUS_MAX_LEN+1];	/*	応答	*/
} CMD_TD_PARAM;

/*	SSID書込み												*/
typedef struct	{
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	char	ssid_status[2 + 1];					/*	SSID変更応答		*/
	char	ssid_value[5 + 1];					/*	SSID内部値			*/
} CMD_SSID_PARAM;

/*	汎用１																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		count;								/*	件数				*/
	char	value00[CONST_C20+1];				/*	値00				*/
	char	value01[CONST_C20+1];				/*	値01				*/
	char	value02[CONST_C20+1];				/*	値02				*/
	char	value03[CONST_C20+1];				/*	値03				*/
	char	value04[CONST_C20+1];				/*	値04				*/
	char	value05[CONST_C20+1];				/*	値05				*/
	char	value06[CONST_C20+1];				/*	値06				*/
	char	value07[CONST_C20+1];				/*	値07				*/
	char	value08[CONST_C20+1];				/*	値08				*/
	char	value09[CONST_C20+1];				/*	値09				*/
	char	value10[CONST_C20+1];				/*	値10				*/
	char	value11[CONST_C20+1];				/*	値11				*/
	char	value12[CONST_C20+1];				/*	値12				*/
	char	value13[CONST_C20+1];				/*	値13				*/
	char	value14[CONST_C20+1];				/*	値14				*/
	char	value15[CONST_C20+1];				/*	値15				*/
	char	value16[CONST_C20+1];				/*	値16				*/
	char	value17[CONST_C20+1];				/*	値17				*/
	char	value18[CONST_C20+1];				/*	値18				*/
	char	value19[CONST_C20+1];				/*	値19				*/
	char	value20[CONST_C20+1];				/*	値20				*/
	char	value21[CONST_C20+1];				/*	値21				*/
	char	value22[CONST_C20+1];				/*	値22				*/
	char	value23[CONST_C20+1];				/*	値23				*/
	char	value24[CONST_C20+1];				/*	値24				*/
	char	value25[CONST_C20+1];				/*	値25				*/
	char	value26[CONST_C20+1];				/*	値26				*/
} CMD_C20X5_PARAM;

/*	汎用２																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		count;								/*	件数				*/
	char	value00[CONST_C30+1];				/*	値00				*/
	char	value01[CONST_C30+1];				/*	値01				*/
	char	value02[CONST_C30+1];				/*	値02				*/
	char	value03[CONST_C30+1];				/*	値03				*/
	char	value04[CONST_C30+1];				/*	値04				*/
	char	value05[CONST_C30+1];				/*	値05				*/
	char	value06[CONST_C30+1];				/*	値06				*/
	char	value07[CONST_C30+1];				/*	値07				*/
	char	value08[CONST_C30+1];				/*	値08				*/
	char	value09[CONST_C30+1];				/*	値09				*/
	char	value10[CONST_C30+1];				/*	値10				*/
} CMD_C30X10_PARAM;


/*	汎用３																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		count;								/*	件数				*/
	char	value00[CONST_C30+1];				/*	値00				*/
	char	value01[CONST_C30+1];				/*	値01				*/
} CMD_C30X1_PARAM;

/*	汎用４																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		count;								/*	件数				*/
	char	value00[CONST_C30+1];				/*	値00				*/
	char	value01[CONST_C30+1];				/*	値01				*/
	char	value02[CONST_C30+1];				/*	値02				*/
	char	value03[CONST_C30+1];				/*	値03				*/
	char	value04[CONST_C30+1];				/*	値04				*/
	char	value05[CONST_C30+1];				/*	値05				*/
} CMD_C30X5_PARAM;

/*	汎用５																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		count;								/*	件数				*/
	char	key1[CONST_HANYO_KEY+1];			/*	キー１				*/
	char	key2[CONST_HANYO_KEY+1];			/*	キー２				*/
	char	key3[CONST_HANYO_KEY+1];			/*	キー３				*/
	char	key4[CONST_HANYO_KEY+1];			/*	キー４				*/
	char	key5[CONST_HANYO_KEY+1];			/*	キー５				*/
	char	reckey1[CONST_HANYO_KEY+1];			/*	データキー			*/
	char	value01[CONST_HANYO_DATA+1];		/*	データ				*/
} CMD_HANYO_PARAM;


/*	汎用６																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		count;								/*	件数([0]に行数)*/
	int		value_count;						/*	(この行の値数)		*/
	char	value00[CONST_C20+1];				/*	値00				*/
	char	value01[CONST_C20+1];				/*	値01				*/
	char	value02[CONST_C20+1];				/*	値02				*/
	char	value03[CONST_C20+1];				/*	値03				*/
	char	value04[CONST_C20+1];				/*	値04				*/
	char	value05[CONST_C20+1];				/*	値05				*/
	char	value06[CONST_C20+1];				/*	値06				*/
	char	value07[CONST_C20+1];				/*	値07				*/
	char	value08[CONST_C20+1];				/*	値08				*/
	char	value09[CONST_C20+1];				/*	値09				*/
	char	value10[CONST_C20+1];				/*	値10				*/
	char	value11[CONST_C20+1];				/*	値11				*/
	char	value12[CONST_C20+1];				/*	値12				*/
	char	value13[CONST_C20+1];				/*	値13				*/
	char	value14[CONST_C20+1];				/*	値14				*/
	char	value15[CONST_C20+1];				/*	値15				*/
	char	value16[CONST_C20+1];				/*	値16				*/
	char	value17[CONST_C20+1];				/*	値17				*/
	char	value18[CONST_C20+1];				/*	値18				*/
	char	value19[CONST_C20+1];				/*	値19				*/
	char	value20[CONST_C20+1];				/*	値20				*/
	char	value21[CONST_C20+1];				/*	値21				*/
	char	value22[CONST_C20+1];				/*	値22				*/
	char	value23[CONST_C20+1];				/*	値23				*/
	char	value24[CONST_C20+1];				/*	値24				*/
	char	value25[CONST_C20+1];				/*	値25				*/
	char	value26[CONST_C20+1];				/*	値26				*/
	char	value27[CONST_C20+1];				/*	値27				*/
	char	value28[CONST_C20+1];				/*	値28				*/
	char	value29[CONST_C20+1];				/*	値29				*/
	char	value30[CONST_C20+1];				/*	値30				*/
	char	value31[CONST_C20+1];				/*	値31				*/
	char	value32[CONST_C20+1];				/*	値32				*/
	char	value33[CONST_C20+1];				/*	値33				*/
	char	value34[CONST_C20+1];				/*	値34				*/
	char	value35[CONST_C20+1];				/*	値35				*/
	char	value36[CONST_C20+1];				/*	値36				*/
	char	value37[CONST_C20+1];				/*	値37				*/
	char	value38[CONST_C20+1];				/*	値38				*/
	char	value39[CONST_C20+1];				/*	値39				*/
	char	value40[CONST_C20+1];				/*	値40				*/
	char	value41[CONST_C20+1];				/*	値41				*/
	char	value42[CONST_C20+1];				/*	値42				*/
	char	value43[CONST_C20+1];				/*	値43				*/
	char	value44[CONST_C20+1];				/*	値44				*/
	char	value45[CONST_C20+1];				/*	値45				*/
	char	value46[CONST_C20+1];				/*	値46				*/
	char	value47[CONST_C20+1];				/*	値47				*/
	char	value48[CONST_C20+1];				/*	値48				*/
	char	value49[CONST_C20+1];				/*	値49				*/
	char	value50[CONST_C20+1];				/*	値50				*/
} CMD_HANYO06_PARAM;

/*	汎用７																*/
typedef struct {
	char	cmd_all[BODY_LINE_MAX_LEN+1];		/*	コマンド行全文		*/
	int		count;								/*	件数				*/
	char	value00[CONST_C200+1];				/*	値00				*/
	char	value01[CONST_C200+1];				/*	値01				*/
	char	value02[CONST_C200+1];				/*	値02				*/
	char	value03[CONST_C200+1];				/*	値03				*/
	char	value04[CONST_C200+1];				/*	値04				*/
	char	value05[CONST_C200+1];				/*	値05				*/
} CMD_C200X5_PARAM;


/*	メール情報構造の定義													*/
typedef struct	{
	char	header[HEADER_MAX_LEN + 1];					/*	メールヘッダ全体		*/
	char	body[BODY_MAX_LEN + 1];						/*	メールボディー全体		*/
	char	from_mailaddr[MAIL_ADDR_MAX_LEN + 1];		/*	ヘッダFromアドレス		*/
	char	to_mailaddr[MAIL_ADDR_MAX_LEN + 1];			/*	ヘッダToアドレス		*/
	char	body_to_mailaddr[MAIL_ADDR_MAX_LEN + 1];	/*	本文中Toアドレス		*/
	int		nc_status_ng;								/*	"NG STATUS NG"有無		*/
	int		no_mailbox;									/*	"no mailbox"有無		*/
	char	sr_typ[1+1];								/*	送受信区分				*/
	char	mail_typ[MAIL_TYP_MAX_LEN+1];				/*	メールタイプ			*/
	int		s_flg;										/*	処理フラグ				*/
	char	message_id[MESSAGE_ID_LEN + 1];				/*	メッセージID(メール)*/
} MAIL_INFO;

/*	アプリケーションログ出力構造体											*/
typedef struct	{
	char	datfile[1024];
	char	equipno[20];
	char	mailaddr[128];
	int		seq;
	int		lineno;
} APLOG_INFO;
/* ------------------------------------------------------------------------ */
/*	外部シンボル参照宣言													*/
/* ------------------------------------------------------------------------ */

char AT_DBCON_1[10];




