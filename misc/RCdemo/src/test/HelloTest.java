/**
 * 
 */
package test;

import static org.junit.Assert.*;
import hello.Goodbye;
import hello.Hello;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import com.thoughtworks.selenium.DefaultSelenium;
import com.thoughtworks.selenium.Selenium;


/**
 * @author ronny
 *
 */
public class HelloTest {

	/**
	 * @throws java.lang.Exception
	 */
	@Before
	public void setUp() throws Exception {
		System.err.println("Starting up the hello test.");
	}

	/**
	 * @throws java.lang.Exception
	 */
	@After
	public void tearDown() throws Exception {
		System.err.println("Starting up the hello test.");
	}

	@Test
	public void test() {
		Goodbye good = new Goodbye();
		Hello.main(null);
		good.sayGoodbye();

		// Instatiate the RC Server
		Selenium selenium = new DefaultSelenium("localhost", 4444, "firefox",
				"http://www.calculator.net");
		selenium.start(); // Start
		selenium.open("/"); // Open the URL
		selenium.windowMaximize();

		// Click on Link Math Calculator
		try {
			selenium.click("xpath=.//*[@id='menu']/div[3]/a");
			Thread.sleep(2500); // Wait for page load

			// Click on Link Percent Calculator
			selenium.click("xpath=.//*[@id='menu']/div[4]/div[3]/a");
			Thread.sleep(4000); // Wait for page load
		} catch (Exception e) {
			e.printStackTrace();
		}

		// Focus on text Box
		selenium.focus("name=cpar1");
		// enter a value in Text box 1
		selenium.type("css=input[name=\"cpar1\"]", "10");

		// enter a value in Text box 2
		selenium.focus("name=cpar2");
		selenium.type("css=input[name=\"cpar2\"]", "50");

		// Click Calculate button
		selenium.click("xpath=.//*[@id='content']/table/tbody/tr/td[2]/input");

		// verify if the result is 5
		String result = selenium.getText(".//*[@id='content']/p[2]");

		if (result == "5") {
			System.out.println("Pass");
		} else {
			System.out.println("Fail");
		}
	}
}
