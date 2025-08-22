// electrostatic_bender.h

// electrostatic_bender.h

/*gpufun*/
void ElectrostaticBender_track_local_particle(
                                ElectrostaticBenderData* el,
                                LocalParticle* part0) {

    /*gpuglmem*/ double* r_matrix = ElectrostaticBenderData_getp_r_matrix(el);

    double const x = LocalParticle_get_x(part0);
    double const px = LocalParticle_get_px(part0);
    double const y = LocalParticle_get_y(part0);
    double const py = LocalParticle_get_py(part0);
    double const zeta = LocalParticle_get_zeta(part0);
    double const delta = LocalParticle_get_delta(part0);

    double const x_new =    r_matrix[0] * x + r_matrix[1] * px + r_matrix[5] * delta;
    double const px_new =   r_matrix[6] * x + r_matrix[7] * px + r_matrix[11] * delta;
    double const y_new =    r_matrix[14] * y + r_matrix[15] * py;
    double const py_new =   r_matrix[21] * py;
    double const zeta_new = r_matrix[24] * x + r_matrix[25] * px + r_matrix[28] * zeta + r_matrix[29] * delta;

    LocalParticle_set_x(part0, x_new);
    LocalParticle_set_px(part0, px_new);
    LocalParticle_set_y(part0, y_new);
    LocalParticle_set_py(part0, py_new);
    LocalParticle_set_zeta(part0, zeta_new);
}
