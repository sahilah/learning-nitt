import java.lang.Byte;
class query2
{
    private int i,current;
    private Byte val;
    private Byte[] a = new Byte[3000];
    public Byte[] getBox()
    {
        makeBox();
        return a;
    }
    
    void Value()
    {
       	current = 0;
    }
    Byte call()
    {
    	current++;
    	val.equals(Byte.valueOf(Double.valueOf(Math.sin(current*Math.PI/24)*100).byteValue()));
    	return  val;
    }
    private void makeBox()
    {
        for(i=0;i<=2999;i++)	
        	a[i]=call();
    }
}