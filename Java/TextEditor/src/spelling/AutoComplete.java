/**
 * 
 */
package spelling;

import java.util.List;

/**
 * @author Christine
 * @author Ronny MacMaster
 */
public interface AutoComplete {
	public List<String> predictCompletions(String prefix, int numCompletions);
}
