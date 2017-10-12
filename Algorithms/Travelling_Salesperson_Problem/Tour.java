
package tsp;

/**
 *
 * @author bprya
 */
public class Tour {
    
    /**
     * Node represents a Node for the linked list Tour, and contains a two dimensional point object, and a
     * pointer to the next node in the list.
     */
    private class Node{
        private Point p;
        private Node next;
    }

    public Tour(){
        // YOUR CODE HERE
    }

    public Tour(Point a, Point b, Point c, Point d){
        // YOUR CODE HERE    
    }

    /**
     * Show prints a list of all point objects in the Tour in the order they are currently in through standard output.
     */
    public void show(){
        // YOUR CODE HERE
    }

    /**
     * Draw utilizes the drawTo method in the Point class to display the points with connecting lines
     * as a way to visualize the current Tour.
     */
    public void draw(){
        // YOUR CODE HERE
    }

    /**
     * The distance method iterates through all of the current nodes in the linked list, calculates the
     * total length of the Tour as a double, and returns it.
     */
    public double distance(){
        // YOUR CODE HERE
        return 0.0;
    }
    
    public int size(){
    	return 0;
    }

    /**
     * insertSmallest reads in the next point and adds it to the current tour after the point where it results 
     * in the least possible increase in tour length.  If there is more than one point that is equidistant,  
     * it will be inserted after the first point that is discovered.
     */
    public void insertSmallest(Point p){
        // YOUR CODE HERE
    }

    /**
     * insertNearest reads in the next point and adds it to the current tour after the point to which it is closest.
     * If there are more than one equidistant points, it will be added after the first point that is discovered.
     */
    public void insertNearest(Point p){
        // YOUR CODE HERE
    }
}
