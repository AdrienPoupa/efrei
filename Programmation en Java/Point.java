public class Point 
{
	private final float x; 
	private final float y; 

	public static void main(String[] args) 
	{
		Point p1 = new Point(0.0F, 0.0F);
		System.out.println(p1.x+" "+p1.y);

		Point p2 = new Point(0.0F, 0.0F);
		System.out.println(p1.equals(p2));
		
		Point p3 = new Point(4.5F, 3.6F);
		System.out.println(p3.toString());
	}

	public Point(final float x, final float y) { this.x = x ; this.y = y ; }

	public Point(final Point p) { this(p.x, p.y) ; }

	public float getX() { return x ; }

	public float getY() { return y ; }

	public boolean isSameAs(final Point p) 
	{
		return ((x == p.x) && (y == p.y)) ;

	}

	
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Point other = (Point) obj;
		if (x != other.x)
			return false;
		if (y != other.y)
			return false;
		return true;
	}

	@Override
	public String toString() {
		return "Point [x=" + x + ", y=" + y + "]";
	}
}