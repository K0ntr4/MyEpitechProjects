const MESSAGE = `USAGE
	./101pong x0 y0 z0 x1 y1 z1 n
DESCRIPTION
	x0 ball abscissa at time t - 1
	y0 ball ordinate at time t - 1
	z0 ball altitude at time t - 1
	x1 ball abscissa at time t
	y1 ball ordinate at time t
	z1 ball altitude at time t
	n time shift (greater than or equal to zero, integer)`;

function help() {
    console.log(MESSAGE);
}

function result(values) {
    console.log('The velocity vector of the ball is:');
    console.log(`(${values.velocityVector.x.toFixed(2)}, ${values.velocityVector.y.toFixed(2)}, ${values.velocityVector.z.toFixed(2)})`);
    console.log(`At time t + ${values.n}, ball coordinates will be:`);
    console.log(`(${values.newPosition.x.toFixed(2)}, ${values.newPosition.y.toFixed(2)}, ${values.newPosition.z.toFixed(2)})`);
    if (values.paddleHit.z === 0) {
        console.log('The incidence angle is:');
        console.log(`${values.incidenceAngle.toFixed(2)} degrees`);
    } else {
        console.log("The ball won't reach the paddle.");
    }
}

module.exports = { help, result };
