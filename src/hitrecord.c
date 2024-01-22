#include "hitrecord.h"

void set_face_normal(hit_record *record, ray *r, vec3 *outward_normal) {
    record->front_face = dot(&r->direction, outward_normal) < 0;
    record->normal = record->front_face ? *outward_normal : neg(outward_normal);
}