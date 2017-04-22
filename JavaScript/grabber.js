/** grabber.js 
 * calculate the expected payout of a grabber.
 * 
 * author: ronny macmaster
 * date: 4/21/2017
 */

/* fill out this map. 
 * example: 4x4 grabber.
 *
 * if you're going to scam that space,
 * put a zero there.
 */
var grabber = [
 [20,  5, 2, 1, 0, 0], // row 1
 [ 5, 10, 5, 1, 0, 0], // row 2
 [ 2,  5, 2, 1, 0, 0], // row 3
 [ 2,  1, 2, 1, 0, 0], // row 4
 [ 0,  0, 0, 0, 0, 0], // row 5
 [ 0,  0, 0, 0, 0, 0], // row 6
]

// calculate the payout and chance of win.
var payout = 0, win = 0;
for(var r = 0; r < 6; r++){
	for(var c = 0; c < 6; c++){
		payout += grabber[r][c] / 36.0;
		win += grabber[r][c] > 0 ? 1 / 36.0 : 0;
	}
}

// report results.
console.log("chances of winning on a given go: %.2f%.", win * 100);
console.log("expected payout per game: %.2fc", payout);
