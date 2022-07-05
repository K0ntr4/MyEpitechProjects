function getVelocityVector(values) {
    const vx = values.currentPosition.x - values.pastPosition.x;
    const vy = values.currentPosition.y - values.pastPosition.y;
    const vz = values.currentPosition.z - values.pastPosition.z;
    const velocity = Math.sqrt(vx ** 2 + vy ** 2 + vz ** 2);
    const velocityVector = { x: vx, y: vy, z: vz, velocity };

    return velocityVector;
}

function getNewPosition(values) {
    const velocity = values.velocityVector;
    const time = values.n;
    const x = velocity.x * time + values.currentPosition.x;
    const y = velocity.y * time + values.currentPosition.y;
    const z = velocity.z * time + values.currentPosition.z;

    return { x, y, z };
}

function getPaddleHit(values) {
    const velocity = values.velocityVector;
    const movement = Math.abs(values.currentPosition.z / velocity.z) || 0;
    const position = {
        x: values.currentPosition.x + velocity.x * movement,
        y: values.currentPosition.y + velocity.y * movement,
        z: values.currentPosition.z + velocity.z * movement,
    };

    return position;
}

function getIncidenceAngle(values) {
    const { velocityVector } = values;
    const hypotenuse = Math.sqrt(velocityVector.x ** 2 + velocityVector.y ** 2 + velocityVector.z ** 2);
    const radians = Math.acos(Math.abs(velocityVector.z / hypotenuse));

    return 90 - (radians * 180) / Math.PI;
}

module.exports = {
    getVelocityVector,
    getNewPosition,
    getPaddleHit,
    getIncidenceAngle,
};
