class Context {
	private:
		int idProcess;
		int ncontext;
		int start, end, timerun;
	public:
		void inicializa(int idP);
		void setStart(int st_);
		void setEnd(int end_);
		void setNcontext(void);
		void setRunningTime(void);		
		int getId(void);
		int getStart(void);
		int getEnd(void);
		int getNc(void)
		int getRunningTime(void)
}
