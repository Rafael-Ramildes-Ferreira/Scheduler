
class Context {
	
	private:
		int idProcess;
		int ncontext;
		int start, end, timerun;
		
	public:
		Context(int idP){
			idProcess = idP;
			ncontext = 0;
			timerun = 0;			
		}
		void setStart(int st_){
			start = st_;
		}
		void setEnd(int end_){
			end = end_;
		}
		void setNcontext(void){
			ncontext = getNc() + 1;
		}
		void setRunningTime(void){
			timerun = getRunningTime() + (getEnd() - getStart());
		}
		
		int getId(void){
			return idProcess;
		}
		int getStart(void){
			return start;
		}
		int getEnd(void){
			return end;
		}		
		int getNc(void){
			return ncontext;
		}
		int getRunningTime(void){
			return timerun;
		}
		
}
