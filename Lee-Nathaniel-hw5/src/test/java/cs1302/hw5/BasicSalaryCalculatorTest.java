package cs1302.hw5;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class BasicSalaryCalculatorTest extends BasicSalaryCalculator{
	private BasicSalaryCalculator basicSalaryCalculator;

	@BeforeEach
	void init(){
		basicSalaryCalculator = new BasicSalaryCalculator();
	}//init

	@AfterEach
	void tearDown(){
		basicSalaryCalculator = null;
	}//tearDown
	
	@Test
	void testBasicSalaryWithValidSalary() {
		double basicSalary = 4000;
		basicSalaryCalculator.setBasicSalary(basicSalary);
		
		double expectedSocialInsurance = basicSalary * 0.25;
		assertEquals(expectedSocialInsurance, basicSalaryCalculator.getSocialInsurance());
		
		double expectedAddionalBonus = basicSalary * 0.1;
		assertEquals(expectedAddionalBonus, basicSalaryCalculator.getAdditionalBonus());
		
		double expectedGross = basicSalary + expectedSocialInsurance + expectedAddionalBonus;
		assertEquals(expectedGross, basicSalaryCalculator.getGrossSalary());
	}
	@Test
	void testBasicSalaryWithInValidSalary() {
		double basicSalary = -100;
		assertThrows(IllegalArgumentException.class, () -> {
		basicSalaryCalculator.setBasicSalary(basicSalary);
		});
	}
}
