/**
 * @file rtap_delay_pd.c
 * @author Thomas Resch <br>
 * Audiocommunication Group, Technical University Berlin <br>
 * University of Applied Sciences Nordwestschweiz (FHNW), Music-Academy, Research and Development <br>
 * A gain object for pure data <br>
 * <br>
 * @brief A Pure Data gain object for adjusting the volume<br>
 * <br>
 * rtap_delay~ allows for adjusting the level<br>
 * of any incoming audio signal. <br>
 * <br>
 */

#include "m_pd.h"
#include "vas_delay.h"

static t_class *rtap_delay_tilde_class;

/**
 * @struct rtap_delay_tilde
 * @brief The Pure Data struct of the rtap_delay~ object. <br>
 * @var rtap_delay_tilde::x_obj Necessary for every signal object in Pure Data <br>
 * @var rtap_delay_tilde::f Also necessary for signal objects, float dummy dataspace <br>
 * for converting a float to signal if no signal is connected (CLASS_MAINSIGNALIN) <br>
 * @var rtap_delay_tilde::gain The gain object for the actual signal processing <br>
 * @var rtap_delay_tilde::x_out A signal outlet for the adjusted signal
 * level of the incoming signal
 */

typedef struct rtap_delay_tilde
{
    t_object  x_obj;
    t_sample f;
    vas_delay *delay;
    t_outlet *x_out;
} rtap_delay_tilde;

/**
 * @related rtap_delay_tilde
 * @brief Calculates the volume adjusted output vector<br>
 * @param w A pointer to the object, input and output vectors. <br>
 * For more information please refer to the Pure Data Docs <br>
 * The function calls the rtap_delay_perform method. <br>
 * @return A pointer to the signal chain right behind the rtap_delay_tilde object. <br>
 */


t_int *rtap_delay_tilde_perform(t_int *w)
{
    rtap_delay_tilde *x = (rtap_delay_tilde *)(w[1]);
    t_sample  *in = (t_sample *)(w[2]);
    t_sample  *out =  (t_sample *)(w[3]);
    int n =  (int)(w[4]);

   vas_delay_process(x->delay, in, out, n);

    /* return a pointer to the dataspace for the next dsp-object */
    return (w+5);
}

/**
 * @related rtap_delay_tilde
 * @brief Adds rtap_delay_tilde_perform to the signal chain. <br>
 * @param x A pointer the rtap_delay_tilde object <br>
 * @param sp A pointer the input and output vectors <br>
 * For more information please refer to the <a href = "https://github.com/pure-data/externals-howto" > Pure Data Docs </a> <br>
 */

void rtap_delay_tilde_dsp(rtap_delay_tilde *x, t_signal **sp)
{
    dsp_add(rtap_delay_tilde_perform, 4, x, sp[0]->s_vec, sp[1]->s_vec, sp[0]->s_n);
}

/**
 * @related rtap_delay_tilde
 * @brief Frees our object. <br>
 * @param x A pointer the rtap_delay_tilde object <br>
 * For more information please refer to the <a href = "https://github.com/pure-data/externals-howto" > Pure Data Docs </a> <br>
 */

void rtap_delay_tilde_free(rtap_delay_tilde *x)
{
    outlet_free(x->x_out);
    vas_delay_free(x->delay);
}

/**
 * @related rtap_delay_tilde
 * @brief Creates a new rtap_delay_tilde object.<br>
 * @param f Sets the initial gain value. <br>
 * For more information please refer to the <a href = "https://github.com/pure-data/externals-howto" > Pure Data Docs </a> <br>
 */

void *rtap_delay_tilde_new(t_floatarg f)
{
    rtap_delay_tilde *x = (rtap_delay_tilde *)pd_new(rtap_delay_tilde_class);
    
    //The main inlet is created automatically
    x->x_out = outlet_new(&x->x_obj, &s_signal);
    x->delay = vas_delay_new(44100);

    return (void *)x;
}

/**
 * @related rtap_delay_tilde
 * @brief Sets the gain adjustment parameter. <br>
 * @param x A pointer the rtap_delay_tilde object <br>
 * @param level Sets the level parameter <br>
 * For more information please refer to the <a href = "https://github.com/pure-data/externals-howto" > Pure Data Docs </a> <br>
 */

// von hier (pd) wird an set Delay in vas delay (C) durchgegeben

void rtap_delay_tilde_setDelayTime(rtap_delay_tilde *x, float delayTime)
{
    vas_delay_setDelayTime(x->delay, delayTime);   
}

/**
 * @related rtap_delay_tilde
 * @brief Setup of rtap_delay_tilde <br>
 * For more information please refer to the <a href = "https://github.com/pure-data/externals-howto" > Pure Data Docs </a> <br>
 */

void rtap_delay_tilde_setup(void)
{
      rtap_delay_tilde_class = class_new(gensym("rtap_delay~"),
            (t_newmethod)rtap_delay_tilde_new,
            (t_method)rtap_delay_tilde_free,
        sizeof(rtap_delay_tilde),
            CLASS_DEFAULT,
            A_DEFFLOAT, 0);

      class_addmethod(rtap_delay_tilde_class, (t_method)rtap_delay_tilde_dsp, gensym("dsp"), 0);

      // this adds the gain message to our object
      class_addmethod(rtap_delay_tilde_class, (t_method)rtap_delay_tilde_setDelayTime, gensym("delaytime"), A_DEFFLOAT,0);

      CLASS_MAINSIGNALIN(rtap_delay_tilde_class, rtap_delay_tilde, f);
}
